// Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)


/* "channel" I/O contributed by Michael Ferguson

   Future Work:
    - Regular expression support (currently favoring RE2 integration)
    - We would like to have a 'serialization' system, including allowing
      the writing of data structures with circular references, and
      encoding the types of classes.
    - Currently, the union tag numbers are per-compile; you could not read
      binary union data written in one Chapel program with another. This problem
      will also apply to class tag numbers once we start encoding types.
    - The Chapel compiler does not currently allow RAII/reference counting
      to work correctly in all cases (bug report 'records containing pointers'
      and test files in test/users/ferguson/{byvalue.chpl,refcnt.chpl};
      as a result, current code might need to close channels and files
      explicitly and/or sharing of channels and files between variables might
      not work correctly.
    - Channels have a lock, and some methods on a channel only make sense
      when the lock is held. In the future (again, once RAII makes sense),
      we might replace this with 'get locked channel' that returns a different
      type that has the methods that can only be used on a locked channel.
    - The error handling strategy here is a bit awkward for the library-writer
      (not so much for the user). A broader exceptions strategy would help
      quite a bit - and some of these interfaces will change when that happens.
    - Fancy features, like adding a bytes or buffer object to a channel
      (so that the channel just refers to it and does not copy it) are
      implemented but not well tested.
    - It would be nice if ioBits:string printed itself in binary instead of
      decimal.
    - Cleaning up to reduce the number of exported symbols, and using enums for
      all constants once 'use enum' is available and we have a way to get
      C constants into Chapel enums.
    - Support for libevent/qthreads system call thread so that we have
      something suitable for writing (in a straightforward manner) a
      multithreaded webserver
    - Doing something reasonable with a file that moves from one node to
      another - namely, when a channel is created with a file that resides
      remotely, if that same file is accessible locally (e.g. with Lustre or
      NFS), we should open a local copy of that file and use that in the
      channel. (not sure how to avoid opening # channels copies of these files
      -- seems that we'd want some way to cache that...).
    - Create leader/follower iterators for ItemReader/ItemWriter so that these
      are as efficient as possible when working with fixed-size data types
      (ie, they can open up channels that are not shared).
*/


use SysBasic;
use Error;

enum iomode {
  r = 1,
  cw = 2,
  rw = 3,
  cwr = 4,
}

enum iokind {
  /* don't change these without updating qio_style.h QIO_NATIVE, etc
     a default of 0 is always reasonable, but you can avoid some
     branches to get faster I/O by setting this to native, big, or little.
     In that case, the style is only consulted for text or string I/O.
     */
  dynamic = 0, // look in iostyle
  native = 1,
  big = 2, /* aka "network" */
  little = 3
}
param iodynamic = iokind.dynamic;
param ionative = iokind.native;
param iobig = iokind.big;
param iolittle = iokind.little;


enum iostringstyle {
  len1b_data = -1,
  len2b_data = -2,
  len4b_data = -4,
  len8b_data = -8,
  lenVb_data = -10,
  data_null = -0x0100,
}
proc stringStyleTerminated(terminator:uint(8)) {
  return -(terminator - iostringstyle.data_null);
}
proc stringStyleNullTerminated() {
  return iostringstyle.data_null;
}
proc stringStyleExactLen(len:int(64)) {
  return len;
}
proc stringStyleWithVariableLength() {
  return iostringstyle.lenVb_data;
}
proc stringStyleWithLength(lengthBytes:int) {
  var x = iostringstyle.lenVb_data;
  select lengthBytes {
    when 0 do x = iostringstyle.lenVb_data;
    when 1 do x = iostringstyle.len1b_data;
    when 2 do x = iostringstyle.len2b_data;
    when 4 do x = iostringstyle.len4b_data;
    when 8 do x = iostringstyle.len8b_data;
    otherwise halt("Unhandled string length prefix size");
  }
  return x;
}

extern const QIO_FDFLAG_UNK:c_int;
extern const QIO_FDFLAG_READABLE:c_int;
extern const QIO_FDFLAG_WRITEABLE:c_int;
extern const QIO_FDFLAG_SEEKABLE:c_int;

extern const QIO_CH_ALWAYS_UNBUFFERED:c_int;
extern const QIO_CH_ALWAYS_BUFFERED:c_int;
extern const QIO_CH_BUFFERED:c_int;

extern const QIO_METHOD_DEFAULT:c_int;
extern const QIO_METHOD_READWRITE:c_int;
extern const QIO_METHOD_PREADPWRITE:c_int;
extern const QIO_METHOD_FREADFWRITE:c_int;
extern const QIO_METHOD_MMAP:c_int;
extern const QIO_METHODMASK:c_int;
extern const QIO_HINT_RANDOM:c_int;
extern const QIO_HINT_SEQUENTIAL:c_int;
extern const QIO_HINT_LATENCY:c_int;
extern const QIO_HINT_BANDWIDTH:c_int;
extern const QIO_HINT_CACHED:c_int;
extern const QIO_HINT_PARALLEL:c_int;
extern const QIO_HINT_DIRECT:c_int;
extern const QIO_HINT_NOREUSE:c_int;

/** NONE means normal operation, nothing special
    to hint. Expect to use NONE most of the time.
    The other hints can be bitwise-ORed in.
 */
const IOHINT_NONE = 0:c_int;

/** RANDOM means we expect random access to a file */
const IOHINT_RANDOM = QIO_HINT_RANDOM;

/** SEQUENTAL means expect sequential access. On
    Linux, this should double the readahead.
 */
const IOHINT_SEQUENTIAL = QIO_HINT_SEQUENTIAL;

/** CACHED means we expect the entire file
    to be cached and/or we pull it in all at
    once. May request readahead on the entire file.
 */
const IOHINT_CACHED = QIO_HINT_CACHED;

/** PARALLEL means that we expect to have many
    channels working with this file in parallel.
    It might change the reading/writing implementation
    to something more efficient in that scenario.
 */
const IOHINT_PARALLEL = QIO_HINT_PARALLEL;

extern type qio_file_ptr_t;
extern const QIO_FILE_PTR_NULL:qio_file_ptr_t;

extern type qio_channel_ptr_t;
extern const QIO_CHANNEL_PTR_NULL:qio_channel_ptr_t;

// also the type for a buffer for qio_file_open_mem.
extern type qbuffer_ptr_t;
extern const QBUFFER_PTR_NULL:qbuffer_ptr_t;

extern type style_char_t = uint(8);

extern const QIO_STRING_FORMAT_WORD:uint(8);
extern const QIO_STRING_FORMAT_BASIC:uint(8);
extern const QIO_STRING_FORMAT_CHPL:uint(8);
extern const QIO_STRING_FORMAT_JSON:uint(8);
extern const QIO_STRING_FORMAT_TOEND:uint(8);

extern record iostyle { // aka qio_style_t
  var binary:uint(8) = 0;
  // binary style choices
  var byteorder:uint(8) = iokind.native:uint(8);
  // string binary style:
  // -1 -- 1 byte of length before
  // -2 -- 2 bytes of length before
  // -4 -- 4 bytes of length before
  // -8 -- 8 bytes of length before
  // -10 -- variable byte length before (hi-bit 1 means more, little endian)
  // -0x01XX -- read until terminator XX is read
  //  + -- nonzero positive -- read exactly this length.
  var str_style:int(64) = -10;
  // text style choices
  var min_width_columns:uint(32) = 0;
  var max_width_columns:uint(32) = max(uint(32));
  var max_width_characters:uint(32) = max(uint(32));
  var max_width_bytes:uint(32) = max(uint(32));

  var string_start:style_char_t = 0x22; // "
  var string_end:style_char_t = 0x22; // "

  /* QIO_STRING_FORMAT_WORD  string is as-is; reading reads until whitespace.
     QIO_STRING_FORMAT_BASIC only escape string_end and \ with \
     QIO_STRING_FORMAT_CHPL  escape string_end \ ' " \n with \
                             and nonprinting characters c = 0xXY with \xXY
     QIO_STRING_FORMAT_JSON  escape string_end " and \ with \,
                             and nonprinting characters c = \uABCD
     QIO_STRING_FORMAT_TOEND string is as-is; reading reads until string_end
   */
  var string_format:uint(8) = 0;
  // numeric scanning/printing choices
  var base:uint(8) = 0;
  var point_char:style_char_t = 0x2e; // .
  var exponent_char:style_char_t = 0x65; // e
  var other_exponent_char:style_char_t = 0x70; // p
  var positive_char:style_char_t = 0x2b; // +;
  var negative_char:style_char_t = 0x2d; // -;
  var i_char:style_char_t = 0x69; // i
  var prefix_base:uint(8) = 1;
  // numeric printing choices
  var pad_char:style_char_t = 0x20; // ' '
  var showplus:uint(8) = 0;
  var uppercase:uint(8) = 0;
  var leftjustify:uint(8) = 0;
  var showpoint:uint(8) = 0;
  var showpointzero:uint(8) = 1;
  var precision:int(32) = -1;
  var realfmt:uint(8) = 0;

  var complex_style:uint(8) = 0;
  var array_style:uint(8) = 0;
  var aggregate_style:uint(8) = 0;
  var tuple_style:uint(8) = 0;
}

extern proc qio_style_init_default(inout s: iostyle);

/* Extern functions */
extern proc qio_file_retain(f:qio_file_ptr_t);
extern proc qio_file_release(f:qio_file_ptr_t);

pragma "no prototype" // FIXME
extern proc qio_file_init(inout file_out:qio_file_ptr_t, fp:_file, fd:fd_t, iohints:c_int, inout style:iostyle, usefilestar:c_int):err_t;
extern proc qio_file_open_access(inout file_out:qio_file_ptr_t, path:string, access:string, iohints:c_int, inout style:iostyle):err_t;
extern proc qio_file_open_tmp(inout file_out:qio_file_ptr_t, iohints:c_int, inout style:iostyle):err_t;
extern proc qio_file_open_mem(inout file_out:qio_file_ptr_t, buf:qbuffer_ptr_t, inout style:iostyle):err_t;

extern proc qio_file_close(f:qio_file_ptr_t):err_t;

extern proc qio_file_lock(f:qio_file_ptr_t):err_t;
extern proc qio_file_unlock(f:qio_file_ptr_t);

/* The general way to make sure data is written without error */
extern proc qio_file_sync(f:qio_file_ptr_t):err_t;

//extern proc qio_file_style_ptr(f:qio_file_ptr_t):qio_style_ptr_t;
extern proc qio_file_get_style(f:qio_file_ptr_t, inout style:iostyle);
extern proc qio_file_set_style(f:qio_file_ptr_t, inout style:iostyle);

pragma "no prototype" // FIXME
extern proc qio_channel_create(inout ch:qio_channel_ptr_t, file:qio_file_ptr_t, hints:c_int, readable:c_int, writeable:c_int, start:int(64), end:int(64), inout style:iostyle):err_t;

pragma "no prototype" // FIXME
extern proc qio_channel_path_offset(threadsafe:c_int, ch:qio_channel_ptr_t, inout path:string, inout offset:int(64)):err_t;

extern proc qio_channel_retain(ch:qio_channel_ptr_t);
extern proc qio_channel_release(ch:qio_channel_ptr_t);

extern proc qio_channel_lock(ch:qio_channel_ptr_t):err_t;
extern proc qio_channel_unlock(ch:qio_channel_ptr_t);

extern proc qio_channel_get_style(ch:qio_channel_ptr_t, inout style:iostyle);
extern proc qio_channel_set_style(ch:qio_channel_ptr_t, inout style:iostyle);

extern proc qio_channel_binary(ch:qio_channel_ptr_t):uint(8);
extern proc qio_channel_byteorder(ch:qio_channel_ptr_t):uint(8);
extern proc qio_channel_str_style(ch:qio_channel_ptr_t):int(64);
extern proc qio_channel_style_element(ch:qio_channel_ptr_t, element:int(64)):int(64);

extern proc qio_channel_flush(threadsafe:c_int, ch:qio_channel_ptr_t):err_t;
extern proc qio_channel_close(threadsafe:c_int, ch:qio_channel_ptr_t):err_t;

extern proc qio_channel_read(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr, len:ssize_t, inout amt_read:ssize_t):err_t;
extern proc qio_channel_read_amt(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr, len:ssize_t):err_t;
extern proc qio_channel_read_byte(threadsafe:c_int, ch:qio_channel_ptr_t):int(32);

extern proc qio_channel_write(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr, len:ssize_t, inout amt_written:ssize_t):err_t;
extern proc qio_channel_write_amt(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr, len:ssize_t):err_t;
extern proc qio_channel_write_byte(threadsafe:c_int, ch:qio_channel_ptr_t, byte:uint(8)):err_t;

extern proc qio_channel_offset_unlocked(ch:qio_channel_ptr_t):int(64);
extern proc qio_channel_advance(threadsafe:c_int, ch:qio_channel_ptr_t, nbytes:int(64)):err_t;
extern proc qio_channel_mark(threadsafe:c_int, ch:qio_channel_ptr_t):err_t;
extern proc qio_channel_revert_unlocked(ch:qio_channel_ptr_t);
extern proc qio_channel_commit_unlocked(ch:qio_channel_ptr_t);

extern proc qio_channel_write_bits(threadsafe:c_int, ch:qio_channel_ptr_t, v:uint(64), nbits:int(8)):err_t;
extern proc qio_channel_flush_bits(threadsafe:c_int, ch:qio_channel_ptr_t):err_t;
extern proc qio_channel_read_bits(threadsafe:c_int, ch:qio_channel_ptr_t, inout v:uint(64), nbits:int(8)):err_t;

pragma "no prototype" // FIXME
extern proc qio_file_path_for_fd(fd:fd_t, inout path:string):err_t;
pragma "no prototype" // FIXME
extern proc qio_file_path_for_fp(fp:_file, inout path:string):err_t;
pragma "no prototype" // FIXME
extern proc qio_file_path(f:qio_file_ptr_t, inout path:string):err_t;
pragma "no prototype" // FIXME
extern proc qio_shortest_path(inout path_out:string, path_in:string):err_t;

extern proc qio_channel_read_int(threadsafe:c_int, byteorder:c_int, ch:qio_channel_ptr_t, inout ptr, len:size_t, issigned:c_int):err_t;
pragma "no prototype" // FIXME
extern proc qio_channel_write_int(threadsafe:c_int, byteorder:c_int, ch:qio_channel_ptr_t, inout ptr, len:size_t, issigned:c_int):err_t;

extern proc qio_channel_read_float(threadsafe:c_int, byteorder:c_int, ch:qio_channel_ptr_t, inout ptr, len:size_t):err_t;
pragma "no prototype" // FIXME
extern proc qio_channel_write_float(threadsafe:c_int, byteorder:c_int, ch:qio_channel_ptr_t, inout ptr, len:size_t):err_t;

extern proc qio_channel_read_complex(threadsafe:c_int, byteorder:c_int, ch:qio_channel_ptr_t, inout re_ptr, inout im_ptr, len:size_t):err_t;
extern proc qio_channel_write_complex(threadsafe:c_int, byteorder:c_int, ch:qio_channel_ptr_t, inout re_ptr, inout im_ptr, len:size_t):err_t;

extern proc qio_channel_read_string(threadsafe:c_int, byteorder:c_int, str_style:int(64), ch:qio_channel_ptr_t, inout s:string, inout len:ssize_t, maxlen:ssize_t):err_t;
extern proc qio_channel_write_string(threadsafe:c_int, byteorder:c_int, str_style:int(64), ch:qio_channel_ptr_t, s:string, len:ssize_t):err_t;

extern proc qio_channel_scan_int(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr, len:size_t, issigned:c_int):err_t;
pragma "no prototype" // FIXME
extern proc qio_channel_print_int(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr, len:size_t, issigned:c_int):err_t;

extern proc qio_channel_scan_float(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr, len:size_t):err_t;
pragma "no prototype" // FIXME
extern proc qio_channel_print_float(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr, len:size_t):err_t;

// These are the same as scan/print float but they assume an 'i' afterwards.
extern proc qio_channel_scan_imag(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr, len:size_t):err_t;
pragma "no prototype" // FIXME
extern proc qio_channel_print_imag(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr, len:size_t):err_t;


extern proc qio_channel_scan_complex(threadsafe:c_int, ch:qio_channel_ptr_t, inout re_ptr, inout im_ptr, len:size_t):err_t;
extern proc qio_channel_print_complex(threadsafe:c_int, ch:qio_channel_ptr_t, inout re_ptr, inout im_ptr, len:size_t):err_t;


extern proc qio_channel_read_char(threadsafe:c_int, ch:qio_channel_ptr_t, inout char:int(32)):err_t;

extern proc qio_nbytes_char(chr:int(32)):c_int;
extern proc qio_encode_to_string(chr:int(32)):string;
extern proc qio_decode_char_buf(inout chr:int(32), inout nbytes:c_int, buf:string, buflen:ssize_t):err_t;

extern proc qio_channel_write_char(threadsafe:c_int, ch:qio_channel_ptr_t, char:int(32)):err_t;
extern proc qio_channel_skip_past_newline(threadsafe:c_int, ch:qio_channel_ptr_t, skipOnlyWs:c_int):err_t;
extern proc qio_channel_write_newline(threadsafe:c_int, ch:qio_channel_ptr_t):err_t;

extern proc qio_channel_scan_string(threadsafe:c_int, ch:qio_channel_ptr_t, inout ptr:string, inout len:ssize_t, maxlen:ssize_t):err_t;
extern proc qio_channel_print_string(threadsafe:c_int, ch:qio_channel_ptr_t, ptr:string, len:ssize_t):err_t;

extern proc qio_channel_scan_literal(threadsafe:c_int, ch:qio_channel_ptr_t, match:string, len:ssize_t, skipws:c_int):err_t;
extern proc qio_channel_scan_literal_2(threadsafe:c_int, ch:qio_channel_ptr_t, match:c_ptr, len:ssize_t, skipws:c_int):err_t;
extern proc qio_channel_print_literal(threadsafe:c_int, ch:qio_channel_ptr_t, match:string, len:ssize_t):err_t;
extern proc qio_channel_print_literal_2(threadsafe:c_int, ch:qio_channel_ptr_t, match:c_ptr, len:ssize_t):err_t;

extern record qio_conv_t {
  var preArg1:uint(8);
  var preArg2:uint(8);
  var preArg3:uint(8);
  var argType:uint(8);
  var literal_is_whitespace:uint(8);
  var literal_length:uint(32);
  var literal:c_ptr;
  var regexp_length:uint(32);
  var regexp:c_ptr;
  var regexp_flags_length:uint(32);
  var regexp_flags:c_ptr;
}

extern const QIO_CONV_UNK:c_int;

extern const QIO_CONV_ARG_TYPE_NUMERIC:c_int;
extern const QIO_CONV_ARG_TYPE_SIGNED:c_int;
extern const QIO_CONV_ARG_TYPE_BINARY_SIGNED:c_int;
extern const QIO_CONV_ARG_TYPE_UNSIGNED:c_int;
extern const QIO_CONV_ARG_TYPE_BINARY_UNSIGNED:c_int;
extern const QIO_CONV_ARG_TYPE_REAL:c_int;
extern const QIO_CONV_ARG_TYPE_BINARY_REAL:c_int;
extern const QIO_CONV_ARG_TYPE_IMAG:c_int;
extern const QIO_CONV_ARG_TYPE_BINARY_IMAG:c_int;
extern const QIO_CONV_ARG_TYPE_COMPLEX:c_int;
extern const QIO_CONV_ARG_TYPE_BINARY_COMPLEX:c_int;

extern const QIO_CONV_ARG_TYPE_CHAR:c_int;
extern const QIO_CONV_ARG_TYPE_STRING:c_int;
extern const QIO_CONV_ARG_TYPE_REPR:c_int;
extern const QIO_CONV_ARG_TYPE_REGEXP:c_int;
extern const QIO_CONV_ARG_TYPE_NONE_REGEXP_LITERAL:c_int;
extern const QIO_CONV_ARG_TYPE_NONE_LITERAL:c_int;

extern const QIO_CONV_SET_MIN_WIDTH_COLS:c_int;
extern const QIO_CONV_SET_MAX_WIDTH_COLS:c_int;
extern const QIO_CONV_SET_MAX_WIDTH_CHARS:c_int;
extern const QIO_CONV_SET_MAX_WIDTH_BYTES:c_int;
extern const QIO_CONV_SET_PRECISION:c_int;
extern const QIO_CONV_SET_STRINGLEN:c_int;
extern const QIO_CONV_SET_TERMINATOR:c_int;
extern const QIO_CONV_SET_STRINGSTART:c_int;
extern const QIO_CONV_SET_STRINGSTARTEND:c_int;
extern const QIO_CONV_SET_STRINGEND:c_int;
extern const QIO_CONV_SET_CAPTURE:c_int;
extern const QIO_CONV_SET_DONE:c_int;

extern proc qio_conv_parse(fmt:string, start:size_t, inout end:size_t, scanning:c_int, inout spec:qio_conv_t, inout style:iostyle):syserr;

extern proc qio_format_error_too_many_args():syserr;
extern proc qio_format_error_too_few_args():syserr;
extern proc qio_format_error_arg_mismatch(arg:int):syserr;
extern proc qio_format_error_bad_regexp():syserr;
extern proc qio_format_error_write_regexp():syserr;

proc defaultIOStyle():iostyle {
  var ret:iostyle;
  qio_style_init_default(ret);
  return ret;
}

proc iostyle.native(str_style:int(64)=stringStyleWithVariableLength()):iostyle {
  var ret = this;
  ret.binary = 1;
  ret.byteorder = iokind.native:uint(8);
  ret.str_style = str_style;
  return ret;
}
proc iostyle.big(str_style:int(64)=stringStyleWithVariableLength()):iostyle {
  var ret = this;
  ret.binary = 1;
  ret.byteorder = iokind.big:uint(8);
  ret.str_style = str_style;
  return ret;
}
proc iostyle.little(str_style:int(64)=stringStyleWithVariableLength()):iostyle  {
  var ret = this;
  ret.binary = 1;
  ret.byteorder = iokind.little:uint(8);
  ret.str_style = str_style;
  return ret;
}
proc iostyle.text(/* args coming later */):iostyle  {
  var ret = this;
  ret.binary = 0;
  return ret;
}



/* fdflag_t specifies how a file can be used. It can be:
  QIO_FDFLAG_UNK,
  QIO_FDFLAG_READABLE,
  QIO_FDFLAG_WRITEABLE,
  QIO_FDFLAG_SEEKABLE
*/
extern type fdflag_t = c_int;

/* Access hints describe how a file will be used.
   These can help optimize. These might be:
  QIO_METHOD_DEFAULT,
  QIO_METHOD_READWRITE,
  QIO_METHOD_P_READWRITE,
  QIO_METHOD_MMAP,
  QIO_HINT_RANDOM,
  QIO_HINT_SEQUENTIAL,
  QIO_HINT_LATENCY,
  QIO_HINT_BANDWIDTH,
  QIO_HINT_CACHED,
  QIO_HINT_NOREUSE
}
*/
extern type iohints = c_int;

record file {
  var home: locale = here;
  var _file_internal:qio_file_ptr_t = QIO_FILE_PTR_NULL;
}

// used for giving old warnings anyways...
enum FileAccessMode { read, write };

param _oldioerr="This program is using old-style I/O which is no longer supported.\n" +
                "See doc/README.io.\n" +
                "You'll probably want something like:\n" +
                "var f = open(filename, iomode.w).writer()\n" + 
                "or\n" + 
                "var f = open(filename, iomode.r).reader()\n";

// This file constructor exists to throw an error for old I/O code.
proc file.file(filename:string="",
               mode:FileAccessMode=FileAccessMode.read,
               path:string=".") {
  compilerError(_oldioerr);
}
proc file.open() {
  compilerError(_oldioerr);
}
proc file.filename : string {
  compilerError(_oldioerr + "file.filename is no longer supported");
}
proc file.mode {
  compilerError(_oldioerr + "file.mode is no longer supported");
}
proc file.isOpen: bool {
  compilerError(_oldioerr + "file.isOpen is no longer supported");
}

// TODO -- shouldn't have to write this this way!
proc chpl__initCopy(x: file) {
  on x.home {
    qio_file_retain(x._file_internal);
  }
  return x;
}

proc =(ret:file, x:file) {
  // retain -- release
  on x.home {
    qio_file_retain(x._file_internal);
  }

  on ret.home {
    qio_file_release(ret._file_internal);
  }

  // compiler will do this copy.
  ret.home = x.home;
  ret._file_internal = x._file_internal;
  return ret;
}

proc file.check() {
  if(1 == is_c_nil(_file_internal)) {
    halt("Operation attempted on an invalid file");
  }
}

/*
proc file.file() {
  this.home = here;
  this._file_internal = QIO_FILE_PTR_NULL;
}
*/

proc file.~file() {
  on this.home {
    qio_file_release(_file_internal);
    this._file_internal = QIO_FILE_PTR_NULL;
  }
}

/*
   We could support file locking and unlocking, but
   at the moment I don't see any use case in which
   it would make sense. 
proc file.lock() {
  on this.home {
    seterr(nil, qio_file_lock(_file_internal));
  }
}
proc file.unlock() {
  on this.home {
    qio_file_unlock(_file_internal);
  }
}
*/

// File style cannot be modified after the file is created;
// this prevents race conditions;
// channel style is protected by channel lock, can be modified.
proc file._style:iostyle {
  check();

  var ret:iostyle;
  on this.home {
    var local_style:iostyle;
    qio_file_get_style(_file_internal, local_style);
    ret = local_style;
  }
  return ret;
}

/* Close a file.
   Alternately, file will be closed when it is no longer referred to */
proc file.close(out error:syserr) {
  check();
  on this.home {
    error = qio_file_close(_file_internal);
  }
}

proc file.close() {
  var err:syserr = ENOERR;
  this.close(err);
  if err then ioerror(err, "in file.close", this.tryGetPath());
}

/* Sync a file to disk. */
proc file.fsync(out error:syserr) {
  check();
  on this.home {
    error = qio_file_sync(_file_internal);
  }
}
proc file.fsync() {
  var err:syserr = ENOERR;
  this.fsync(err);
  if err then ioerror(err, "in file.fsync", this.tryGetPath());
}


/* Get the path to a file. */
proc file.getPath(out error:syserr) : string {
  check();
  var ret:string;
  on this.home {
    var tmp:string;
    var tmp2:string;
    error = qio_file_path(_file_internal, tmp);
    if !error {
      error = qio_shortest_path(tmp2, tmp);
    }
    if !error {
      ret = tmp2;
    } else {
      ret = "unknown";
    }
  }
 return ret; 
}

proc file.tryGetPath() : string {
  var err:syserr = ENOERR;
  var ret:string;
  ret = this.getPath(err);
  if err then return "unknown";
  else return ret;
}

proc file.path : string {
  var err:syserr = ENOERR;
  var ret:string;
  ret = this.getPath(err);
  if err then ioerror(err, "in file.path");
}

// these strings are here (vs in _modestring)
// in an attempt to avoid string copies, leaks,
// and unnecessary allocations.
const _r = "r";
const _rw  = "r+";
const _cw = "w";
const _cwr = "w+";

proc _modestring(mode:iomode) {
  select mode {
    when iomode.r do return _r;
    when iomode.rw do return _rw;
    when iomode.cw do return _cw;
    when iomode.cwr do return _cwr;
    otherwise halt("Invalid mode");
  }
}

proc open(out error:syserr, path:string, mode:iomode, hints:iohints=IOHINT_NONE, style:iostyle = defaultIOStyle()):file {
  var local_style = style;
  var ret:file;
  ret.home = here;
  error = qio_file_open_access(ret._file_internal, path, _modestring(mode), hints, local_style);
  return ret;
}
proc open(path:string, mode:iomode, hints:iohints=IOHINT_NONE, style:iostyle = defaultIOStyle()):file {
  var err:syserr = ENOERR;
  var ret = open(err, path, mode, hints, style);
  if err then ioerror(err, "in open", path);
  return ret;
}
proc openfd(fd: fd_t, out error:syserr, hints:iohints=IOHINT_NONE, style:iostyle = defaultIOStyle()):file {
  var local_style = style;
  var ret:file;
  ret.home = here;
  error = qio_file_init(ret._file_internal, chpl_cnullfile(), fd, hints, local_style, 0);
  return ret;
}
proc openfd(fd: fd_t, hints:iohints=IOHINT_NONE, style:iostyle = defaultIOStyle()):file {
  var err:syserr = ENOERR;
  var ret = openfd(fd, err, hints, style);
  if err {
    var path:string;
    var e2:syserr = ENOERR;
    e2 = qio_file_path_for_fd(fd, path);
    if e2 then path = "unknown";
    ioerror(err, "in openfd", path);
  }
  return ret;
}
proc openfp(fp: _file, out error:syserr, hints:iohints=IOHINT_NONE, style:iostyle = defaultIOStyle()):file {
  var local_style = style;
  var ret:file;
  ret.home = here;
  error = qio_file_init(ret._file_internal, fp, -1, hints, local_style, 1);
  return ret;
}
proc openfp(fp: _file, hints:iohints=IOHINT_NONE, style:iostyle = defaultIOStyle()):file {
  var err:syserr = ENOERR;
  var ret = openfp(fp, err, hints, style);
  if err {
    var path:string;
    var e2:syserr = ENOERR;
    e2 = qio_file_path_for_fp(fp, path);
    if e2 then path = "unknown";
    ioerror(err, "in openfp", path);
  }
  return ret;
}

proc opentmp(out error:syserr, hints:iohints=IOHINT_NONE, style:iostyle = defaultIOStyle()):file {
  var local_style = style;
  var ret:file;
  ret.home = here;
  error = qio_file_open_tmp(ret._file_internal, hints, local_style);
  return ret;
}
proc opentmp(hints:iohints=IOHINT_NONE, style:iostyle = defaultIOStyle()):file {
  var err:syserr = ENOERR;
  var ret = opentmp(err, hints, style);
  if err then ioerror(err, "in opentmp");
  return ret;
}

proc openmem(out error:syserr, style:iostyle = defaultIOStyle()) {
  var local_style = style;
  var ret:file;
  ret.home = here;
  error = qio_file_open_mem(ret._file_internal, QBUFFER_PTR_NULL, local_style);
  return ret;
}
proc openmem(style:iostyle = defaultIOStyle()):file {
  var err:syserr = ENOERR;
  var ret = openmem(err, style);
  if err then ioerror(err, "in openmem");
  return ret;
}



/* in the future, this will be an interface.
   */
record channel {
  param writing:bool;
  param kind:iokind;
  param locking:bool;
  var home:locale;
  var _channel_internal:qio_channel_ptr_t = QIO_CHANNEL_PTR_NULL;
}

// TODO -- shouldn't have to write this this way!
proc chpl__initCopy(x: channel) {
  on x.home {
    qio_channel_retain(x._channel_internal);
  }
  return x;
}

proc =(ret:channel, x:channel) {
  // retain -- release
  on x.home {
    qio_channel_retain(x._channel_internal);
  }

  on ret.home {
    qio_channel_release(ret._channel_internal);
  }

  ret.home = x.home;
  ret._channel_internal = x._channel_internal;
  return ret;
}

proc channel.channel(param writing:bool, param kind:iokind, param locking:bool, f:file, out error:syserr, hints:c_int, start:int(64), end:int(64), style:iostyle) {
  on f.home {
    this.home = f.home;
    var local_style = style;
    if kind != iokind.dynamic {
      local_style.binary = true;
      local_style.byteorder = kind:uint(8);
    }
    error = qio_channel_create(this._channel_internal, f._file_internal, hints, !writing, writing, start, end, local_style);
  }
}

proc channel.~channel() {
  on this.home {
    qio_channel_release(_channel_internal);
    this._channel_internal = QIO_CHANNEL_PTR_NULL;
  }
}

// Used to represent a Unicode character
record ioChar {
  var ch:int(32);
  proc writeThis(f: Writer) {
    halt("ioChar.writeThis must be written in Writer subclasses");
  }
}
inline proc _cast(type t, x: ioChar) where t == string {
  return qio_encode_to_string(x.ch);
}


// Used to represent "\n", but never escaped...
record ioNewline {
  // Normally, we will skip anything at all to get to a \n,
  // but if skipWhitespaceOnly is set, it will be an error
  // if we run into non-space charcters other than \n.
  var skipWhitespaceOnly: bool = false;
  proc writeThis(f: Writer) {
    // Normally this is handled explicitly in read/write.
    f.write("\n");
  }
}
inline proc _cast(type t, x: ioNewline) where t == string {
  return "\n";
}

// Used to represent a constant string we want to read or write...
record ioLiteral {
  var val: string;
  var ignoreWhiteSpace: bool = true;
  proc writeThis(f: Writer) {
    // Normally this is handled explicitly in read/write.
    f.write(val);
  }
}

inline proc _cast(type t, x: ioLiteral) where t == string {
  return x.val;
}

// Used to represent some number of bits we want to read or write...
record ioBits {
  var v:uint(64);
  var nbits:int(8);
  proc writeThis(f: Writer) {
    // Normally this is handled explicitly in read/write.
    f.write(v);
  }
}

inline proc _cast(type t, x: ioBits) where t == string {
  return "ioBits(v=" + x.v:string + ", nbits=" + x.nbits:string + ")";
}


proc channel._ch_ioerror(error:syserr, msg:string) {
  var path:string = "unknown";
  var offset:int(64) = -1;
  on this.home {
    var tmp_path:string;
    var tmp_offset:int(64);
    var err:syserr = ENOERR;
    err = qio_channel_path_offset(locking, _channel_internal, tmp_path, tmp_offset);
    if !err {
      path = tmp_path;
      offset = tmp_offset;
    }
  }
  ioerror(error, msg, path, offset);
}
proc channel._ch_ioerror(errstr:string, msg:string) {
  var path:string = "unknown";
  var offset:int(64) = -1;
  on this.home {
    var tmp_path:string;
    var tmp_offset:int(64);
    var err:syserr = ENOERR;
    err = qio_channel_path_offset(locking, _channel_internal, tmp_path, tmp_offset);
    if !err {
      path = tmp_path;
      offset = tmp_offset;
    }
  }
  ioerror(errstr, msg, path, offset);
}


inline proc channel.lock(out error:syserr) {
  error = ENOERR;
  if locking {
    on this.home {
      error = qio_channel_lock(_channel_internal);
    }
  }
}
inline proc channel.lock() {
  var err:syserr = ENOERR;
  this.lock(err);
  if err then this._ch_ioerror(err, "in lock");
}

inline proc channel.unlock() {
  if locking {
    on this.home {
      qio_channel_unlock(_channel_internal);
    }
  }
}

proc channel.offset():int(64) {
  var ret:int(64);
  on this.home {
    this.lock();
    ret = qio_channel_offset_unlocked(_channel_internal);
    this.unlock();
  }
  return ret;
}

proc channel.advance(amount:int(64), ref error:syserr) {
  on this.home {
    this.lock();
    error = qio_channel_advance(false, _channel_internal);
    this.unlock();
  }
}
proc channel.advance(amount:int(64)) {
  on this.home {
    this.lock();
    var err = qio_channel_advance(false, _channel_internal);
    if err then this._ch_ioerror(err, "in advance");
    this.unlock();
  }
}



// you should have a lock before you use these...

inline proc channel._offset():int(64) {
  var ret:int(64);
  on this.home {
    ret = qio_channel_offset_unlocked(_channel_internal);
  }
  return ret;
}

inline proc channel._mark():syserr {
  return qio_channel_mark(false, _channel_internal);
}
inline proc channel._revert() {
  qio_channel_revert_unlocked(_channel_internal);
}
inline proc channel._commit() {
  qio_channel_commit_unlocked(_channel_internal);
}
proc channel._style():iostyle {
  var ret:iostyle;
  on this.home {
    var local_style:iostyle;
    qio_channel_get_style(_channel_internal, local_style);
    ret = local_style;
  }
  return ret;
}
proc channel._set_style(style:iostyle) {
  on this.home {
    var local_style:iostyle = style;
    qio_channel_set_style(_channel_internal, local_style);
  }
}

proc file.reader(out error:syserr, param kind=iokind.dynamic, param locking=true, start:int(64) = 0, end:int(64) = max(int(64)), hints:iohints = IOHINT_NONE, style:iostyle = this._style): channel(false, kind, locking) {
  check();

  var ret:channel(false, kind, locking);
  on this.home {
    ret = new channel(false, kind, locking, this, error, hints, start, end, style);
  }
  return ret;
}
proc file.reader(param kind=iokind.dynamic, param locking=true, start:int(64) = 0, end:int(64) = max(int(64)), hints:iohints = IOHINT_NONE, style:iostyle = this._style): channel(false, kind, locking) {
  var err:syserr = ENOERR;
  var ret = this.reader(err, kind, locking, start, end, hints, style);
  if err then ioerror(err, "in file.reader", this.tryGetPath());
  return ret;
}
// for convenience..
proc file.lines(out error:syserr, param locking:bool = true, start:int(64) = 0, end:int(64) = max(int(64)), hints:iohints = IOHINT_NONE, style:iostyle = this._style) {
  check();

  style.string_format = QIO_STRING_FORMAT_TOEND;
  style.string_end = 0x0a; // '\n'

  param kind = iokind.dynamic;
  var ret:ItemReader(string, kind, locking);
  on this.home {
    var ch = new channel(false, kind, locking, this, error, hints, start, end, style);
    ret = new ItemReader(string, kind, locking, ch);
  }
  return ret;
}
proc file.lines(param locking:bool = true, start:int(64) = 0, end:int(64) = max(int(64)), hints:iohints = IOHINT_NONE, style:iostyle = this._style) {
  var err:syserr = ENOERR;
  var ret = this.lines(err, locking, start, end, hints, style);
  if err then ioerror(err, "in file.lines", this.tryGetPath());
  return ret;
}


proc file.writer(out error:syserr, param kind=iokind.dynamic, param locking=true, start:int(64) = 0, end:int(64) = max(int(64)), hints:iohints = IOHINT_NONE, style:iostyle = this._style): channel(true,kind,locking) {
  check();

  var ret:channel(true, kind, locking);
  on this.home {
    ret = new channel(true, kind, locking, this, error, hints, start, end, style);
  }
  return ret;
}
proc file.writer(param kind=iokind.dynamic, param locking=true, start:int(64) = 0, end:int(64) = max(int(64)), hints:c_int = 0, style:iostyle = this._style): channel(true,kind,locking) 
{
  var err:syserr = ENOERR;
  var ret = this.writer(err, kind, locking, start, end, hints, style);

  if err then ioerror(err, "in file.writer", this.tryGetPath());
  return ret;
}

proc _isIoPrimitiveType(type t) param return
  _isPrimitiveType(t) || _isComplexType(t) ||
  _isImagType(t) || _isEnumeratedType(t);

 proc _isIoPrimitiveTypeOrNewline(type t) param return
  _isIoPrimitiveType(t) || t == ioNewline || t == ioLiteral || t == ioChar || t == ioBits;

const _trues = ("true",);
const _falses = ("false",);
const _i = "i";

// Read routines for all primitive types.
proc _read_text_internal(_channel_internal:qio_channel_ptr_t, out x:?t):syserr where _isIoPrimitiveType(t) {
  if _isBooleanType(t) {
    var num = _trues.size;
    var err:syserr = ENOERR;
    var got:bool;

    err = EFORMAT;

    for i in 1..num {
      err = qio_channel_scan_literal(false, _channel_internal, _trues(i), (_trues(i).length):ssize_t, 1);
      if !err {
        got = true;
        break;
      } else if err == EEOF {
        break;
      }
      err = qio_channel_scan_literal(false, _channel_internal, _falses(i), (_falses(i).length):ssize_t, 1);
      if !err {
        got = false;
        break;
      } else if err == EEOF {
        break;
      }
    }

    if !err then x = got;
    return err;
  } else if _isIntegralType(t) {
    // handles int types
    return qio_channel_scan_int(false, _channel_internal, x, numBytes(t), _isSignedType(t));
  } else if _isRealType(t) {
    // handles real
    return qio_channel_scan_float(false, _channel_internal, x, numBytes(t));
  } else if _isImagType(t) {
    return qio_channel_scan_imag(false, _channel_internal, x, numBytes(t));
    /*
    var err = qio_channel_mark(false, _channel_internal);
    if err then return err;

    err = qio_channel_scan_float(false, _channel_internal, x, numBytes(t));
    if !err {
      err = qio_channel_scan_literal(false, _channel_internal, _i, 1, false);
    }
    if !err {
      qio_channel_commit_unlocked(_channel_internal);
    } else {
      qio_channel_revert_unlocked(_channel_internal);
    }
    return err;
    */
  } else if _isComplexType(t)  {
    // handle complex types
    var re:x.re.type;
    var im:x.im.type;
    var err:syserr = ENOERR;
    err = qio_channel_scan_complex(false, _channel_internal, re, im, numBytes(x.re.type));
    x = (re, im):t; // cast tuple to complex to get complex num.
    return err;
  } else if t == string {
    // handle string
    var len:ssize_t;
    return qio_channel_scan_string(false, _channel_internal, x, len, -1);
  } else if _isEnumeratedType(t) {
    var err:syserr = ENOERR;
    for i in chpl_enumerate(t) {
      var str:string = i:string;
      var slen:ssize_t = str.length:ssize_t;
      err = qio_channel_scan_literal(false, _channel_internal, str, slen, 1);
      if !err {
        x = i;
        break;
      } else if err != EFORMAT then break;
    }
    return err;
  } else {
    compilerError("Unknown primitive type in _read_text_internal ", typeToString(t));
  }
  return EINVAL;
}

proc _write_text_internal(_channel_internal:qio_channel_ptr_t, x:?t):syserr where _isIoPrimitiveType(t) {
  if _isBooleanType(t) {
    if x {
      return qio_channel_print_literal(false, _channel_internal, _trues(1), _trues(1).length:ssize_t);
    } else {
      return qio_channel_print_literal(false, _channel_internal, _falses(1), _falses(1).length:ssize_t);
    }
  } else if _isIntegralType(t) {
    // handles int types
    return qio_channel_print_int(false, _channel_internal, x, numBytes(t), _isSignedType(t));

  } else if _isRealType(t) {
    // handles real
    return qio_channel_print_float(false, _channel_internal, x, numBytes(t));
  } else if _isImagType(t) {
    return qio_channel_print_imag(false, _channel_internal, x, numBytes(t));
    /*var err = qio_channel_mark(false, _channel_internal);
    if err then return err;

    err = qio_channel_print_float(false, _channel_internal, x, numBytes(t));
    if err == 0 {
      err = qio_channel_print_literal(false, _channel_internal, _i, 1);
    }
    if err == 0 {
      qio_channel_commit_unlocked(_channel_internal);
    } else {
      qio_channel_revert_unlocked(_channel_internal);
    }
    return err;*/
  } else if _isComplexType(t)  {
    // handle complex types
    var re = x.re;
    var im = x.im;
    return qio_channel_print_complex(false, _channel_internal, re, im, numBytes(x.re.type));
  } else if t == string {
    // handle string
    return qio_channel_print_string(false, _channel_internal, x, x.length:ssize_t);
  } else if _isEnumeratedType(t) {
    var s = x:string;
    return qio_channel_print_literal(false, _channel_internal, s, s.length:ssize_t);
  } else {
    compilerError("Unknown primitive type in _write_text_internal ", typeToString(t));
  }
  return EINVAL;
}

inline proc _read_binary_internal(_channel_internal:qio_channel_ptr_t, param byteorder:iokind, out x:?t):syserr where _isIoPrimitiveType(t) {
  if _isBooleanType(t) {
    var got:int(32);
    got = qio_channel_read_byte(false, _channel_internal);
    if got >= 0 {
      x = (got != 0);
      return ENOERR;
    } else {
      return (-got):syserr;
    }
  } else if _isIntegralType(t) {
    if numBytes(t) == 1 {
      var got:int(32);
      got = qio_channel_read_byte(false, _channel_internal);
      if got >= 0 {
        x = (got:uint(8)):t;
        return ENOERR;
      } else {
        return (-got):syserr;
      }
    } else {
      // handles int types
      return qio_channel_read_int(false, byteorder, _channel_internal, x, numBytes(t), _isSignedType(t));
    }
  } else if _isFloatType(t) {
    // handles real, imag
    return qio_channel_read_float(false, byteorder, _channel_internal, x, numBytes(t));
  } else if _isComplexType(t)  {
    // handle complex types
    var re:x.re.type;
    var im:x.im.type;
    var err:syserr = ENOERR;
    err = qio_channel_read_complex(false, byteorder, _channel_internal, re, im, numBytes(x.re.type));
    x = (re, im):t; // cast tuple to complex to get complex num.
    return err;
  } else if t == string {
    // handle string
    var len:ssize_t;
    return qio_channel_read_string(false, byteorder, qio_channel_str_style(_channel_internal), _channel_internal, x, len, -1);
  } else if _isEnumeratedType(t) {
    var i:enum_mintype(t);
    var err:syserr = ENOERR;
    err = qio_channel_read_int(false, byteorder, _channel_internal, i, numBytes(i.type), _isSignedType(i.type));
    x = i:t;
    return err;
  } else {
    compilerError("Unknown primitive type in _read_binary_internal ", typeToString(t));
  }
  return EINVAL;
}

inline proc _write_binary_internal(_channel_internal:qio_channel_ptr_t, param byteorder:iokind, x:?t):syserr where _isIoPrimitiveType(t) {
  if _isBooleanType(t) {
    var zero_one:uint(8) = if x then 1:uint(8) else 0:uint(8);
    return qio_channel_write_byte(false, _channel_internal, zero_one);
  } else if _isIntegralType(t) {
    if numBytes(t) == 1 {
      return qio_channel_write_byte(false, _channel_internal, x:uint(8));
    } else {
      // handles int types
      return qio_channel_write_int(false, byteorder, _channel_internal, x, numBytes(t), _isSignedType(t));
    }
  } else if _isFloatType(t) {
    // handles real, imag
    return qio_channel_write_float(false, byteorder, _channel_internal, x, numBytes(t));
  } else if _isComplexType(t)  {
    // handle complex types
    var re = x.re;
    var im = x.im;
    return qio_channel_write_complex(false, byteorder, _channel_internal, re, im, numBytes(x.re.type));
  } else if t == string {
    return qio_channel_write_string(false, byteorder, qio_channel_str_style(_channel_internal), _channel_internal, x, x.length: ssize_t);
  } else if _isEnumeratedType(t) {
    var i:enum_mintype(t) = x:enum_mintype(t);
    return qio_channel_write_int(false, byteorder, _channel_internal, i, numBytes(i.type), _isSignedType(i.type));
  } else {
    compilerError("Unknown primitive type in write_binary_internal ", typeToString(t));
  }
  return EINVAL;
}

// Channel must be locked, must be running on this.home
// x is inout because it might contain a literal string.
inline proc _read_one_internal(_channel_internal:qio_channel_ptr_t, param kind:iokind, inout x:?t):syserr where _isIoPrimitiveTypeOrNewline(t) {
  var e:syserr = ENOERR;
  if t == ioNewline {
    return qio_channel_skip_past_newline(false, _channel_internal, x.skipWhitespaceOnly);
  } else if t == ioChar {
    return qio_channel_read_char(false, _channel_internal, x.ch);
  } else if t == ioLiteral {
    //writeln("in scan literal ", x.val);
    return qio_channel_scan_literal(false, _channel_internal, x.val, x.val.length: ssize_t, x.ignoreWhiteSpace);
    //e = qio_channel_scan_literal(false, _channel_internal, x.val, x.val.length, x.ignoreWhiteSpace);
    //writeln("Scanning literal ", x.val,  " yeilded error ", e);
    //return e;
  } else if t == ioBits {
    return qio_channel_read_bits(false, _channel_internal, x.v, x.nbits);
  } else if kind == iokind.dynamic {
    var binary:uint(8) = qio_channel_binary(_channel_internal);
    var byteorder:uint(8) = qio_channel_byteorder(_channel_internal);
    if binary {
      select byteorder {
        when iokind.big    do e = _read_binary_internal(_channel_internal, iokind.big, x);
        when iokind.little do e = _read_binary_internal(_channel_internal, iokind.little, x);
        otherwise             e = _read_binary_internal(_channel_internal, iokind.native, x);
      }
    } else {
      e = _read_text_internal(_channel_internal, x);
    }
  } else {
    e = _read_binary_internal(_channel_internal, kind, x);
  }
  return e;
}

// Channel must be locked, must be running on this.home
inline proc _write_one_internal(_channel_internal:qio_channel_ptr_t, param kind:iokind, x:?t):syserr where _isIoPrimitiveTypeOrNewline(t) {
  var e:syserr = ENOERR;
  if t == ioNewline {
    return qio_channel_write_newline(false, _channel_internal);
  } else if t == ioChar {
    return qio_channel_write_char(false, _channel_internal, x.ch);
  } else if t == ioLiteral {
    return qio_channel_print_literal(false, _channel_internal, x.val, x.val.length:ssize_t);
  } else if t == ioBits {
    return qio_channel_write_bits(false, _channel_internal, x.v, x.nbits);
  } else if kind == iokind.dynamic {
    var binary:uint(8) = qio_channel_binary(_channel_internal);
    var byteorder:uint(8) = qio_channel_byteorder(_channel_internal);
    if binary {
      select byteorder {
        when iokind.big    do e = _write_binary_internal(_channel_internal, iokind.big, x);
        when iokind.little do e = _write_binary_internal(_channel_internal, iokind.little, x);
        otherwise             e = _write_binary_internal(_channel_internal, iokind.native, x);
      }
    } else {
      e = _write_text_internal(_channel_internal, x);
    }
  } else {
    e = _write_binary_internal(_channel_internal, kind, x);
  }
  return e;
}

inline proc _read_one_internal(_channel_internal:qio_channel_ptr_t, param kind:iokind, inout x:?t):syserr {
  var reader = new ChannelReader(_channel_internal=_channel_internal);
  var err:syserr = ENOERR;
  reader.read(x);
  err = reader.err;
  delete reader;
  return err;
}

inline proc _write_one_internal(_channel_internal:qio_channel_ptr_t, param kind:iokind, x:?t):syserr {
  var writer = new ChannelWriter(_channel_internal=_channel_internal);
  var err:syserr = ENOERR;
  writer.write(x);
  err = writer.err;
  delete writer;
  return err;
}

/* Returns true if we read all the args,
   false if we encountered EOF (or possibly another error and didn't halt)*/
inline proc channel.read(inout args ...?k,
                  out error:syserr):bool {
  if writing then compilerError("read on write-only channel");
  error = ENOERR;
  on this.home {
    this.lock();
    for param i in 1..k {
      if !error {
        error = _read_one_internal(_channel_internal, kind, args[i]);
      }
    }
    this.unlock();
  }
  return !error;
}
var _arg_to_proto_names = ("a", "b", "c", "d", "e", "f");
proc _args_to_proto(args ...?k,
                    preArg:string) {
  var err_args:string = "";
  for param i in 1..k {
    var name:string;
    if i <= _arg_to_proto_names.size then name = _arg_to_proto_names(i);
    else name = "x" + i:string;
    err_args += preArg + name + ":" + typeToString(args(i).type);
    if i != k then err_args += ", ";
  }
  return err_args;
}

inline proc channel.read(inout args ...?k):bool {
  var e:syserr = ENOERR;
  this.read((...args), error=e);
  if !e then return true;
  else if e == EEOF then return false;
  else {
    this._ch_ioerror(e, "in channel.read(" +
                        _args_to_proto((...args), preArg="inout ") +
                        ")");
    return false;
  }
}
proc channel.read(inout args ...?k,
                  style:iostyle,
                  out error:syserr):bool {
  if writing then compilerError("read on write-only channel");
  error = ENOERR;
  on this.home {
    this.lock();
    var save_style = this._style();
    this._set_style(style);
    for param i in 1..k {
      if !error {
        error = _read_one_internal(_channel_internal, kind, args[i]);
      }
    }
    this._set_style(save_style);
    this.unlock();
  }
  return !error;
}
proc channel.read(inout args ...?k,
                  style:iostyle):bool {
  var e:syserr = ENOERR;
  this.read((...args), style=iostyle, error=e);
  if !e then return true;
  else if e == EEOF then return false;
  else {
    this._ch_ioerror(e, "in channel.read(" +
                        _args_to_proto((...args), preArg="inout ") +
                        "style:iostyle)");
    return false;
  }
}

proc channel.readline(inout arg:string, out error:syserr):bool {
  if writing then compilerError("read on write-only channel");
  error = ENOERR;
  on this.home {
    this.lock();
    var save_style = this._style();
    var mystyle = save_style.text();
    mystyle.string_format = QIO_STRING_FORMAT_TOEND;
    mystyle.string_end = 0x0a; // ascii newline.
    this._set_style(mystyle);
    error = _read_one_internal(_channel_internal, iokind.dynamic, arg);
    this._set_style(save_style);
    this.unlock();
  }
  return !error;
}
proc channel.readline(inout arg:string):bool {
  var e:syserr = ENOERR;
  this.readline(arg, error=e);
  if !e then return true;
  else if e == EEOF then return false;
  else {
    this._ch_ioerror(e, "in channel.readline(inout arg:string)");
    return false;
  }
}

inline proc channel.readbits(out v:uint(64), nbits:int(8), out error:syserr):bool {
  var tmp:ioBits;
  var ret:bool;

  error = ENOERR;

  tmp.nbits = nbits;
  ret = this.read(tmp, error=error);
  v = tmp.v;

  return ret;
}
proc channel.readbits(out v:uint(64), nbits:int(8)):bool {
  var e:syserr = ENOERR;
  this.readbits(v, nbits, error=e);
  if !e then return true;
  else if e == EEOF then return false;
  else {
    this._ch_ioerror(e, "in channel.readbits(out v:uint(64), nbits:int(8))");
    return false;
  }
}

inline proc channel.writebits(v:uint(64), nbits:int(8), out error:syserr):bool {
  return this.write(new ioBits(v, nbits), error=error);
}
proc channel.writebits(v:uint(64), nbits:int(8)):bool {
  var e:syserr = ENOERR;
  this.writebits(v, nbits, error=e);
  if !e then return true;
  else {
    this._ch_ioerror(e, "in channel.writebits(v:uint(64), nbits:int(8))");
    return false;
  }
}



proc channel.readln(out error:syserr):bool {
  var nl = new ioNewline();
  return this.read(nl, error=error);
}
proc channel.readln():bool {
  var nl = new ioNewline();
  return this.read(nl);
}


proc channel.readln(inout args ...?k):bool {
  var nl = new ioNewline();
  return this.read((...args), nl);
}
proc channel.readln(inout args ...?k,
                    out error:syserr):bool {
  var nl = new ioNewline();
  return this.read((...args), nl, error=error);
}
proc channel.readln(inout args ...?k,
                    style:iostyle,
                    out error:syserr):bool {
  var nl = new ioNewline();
  return this.read((...args), nl, style=style, error=error);
}
proc channel.readln(inout args ...?k,
                    style:iostyle):bool {
  var nl = new ioNewline();
  return this.read((...args), nl, style=style);
}

proc channel.read(type t) {
  var tmp:t;
  var e:syserr = ENOERR;
  this.read(tmp, error=e);
  if e then this._ch_ioerror(e, "in channel.read(type)");
  return tmp;
}
proc channel.readln(type t) {
  var tmp:t;
  var e:syserr = ENOERR;
  this.readln(tmp, error=e);
  if e then this._ch_ioerror(e, "in channel.readln(type)");
  return tmp;
}
// Read/write tuples of types.
proc channel.readln(type t ...?numTypes) where numTypes > 1 {
  var tupleVal: t;
  for param i in 1..(numTypes-1) do
    tupleVal(i) = this.read(t(i));
  tupleVal(numTypes) = this.readln(t(numTypes));
  return tupleVal;
}
proc channel.read(type t ...?numTypes) where numTypes > 1 {
  var tupleVal: t;
  for param i in 1..numTypes do
    tupleVal(i) = this.read(t(i));
  return tupleVal;
}

inline proc channel.write(args ...?k, out error:syserr):bool {
  if !writing then compilerError("write on read-only channel");
  error = ENOERR;
  on this.home {
    this.lock();
    for param i in 1..k {
      if !error {
        error = _write_one_internal(_channel_internal, kind, args(i));
      }
    }
    this.unlock();
  }
  return !error;
}

inline proc channel.write(args ...?k):bool {
  var e:syserr = ENOERR;
  this.write((...args), error=e);
  if !e then return true;
  else {
    this._ch_ioerror(e, "in channel.write(" +
                        _args_to_proto((...args), preArg="") +
                        ")");
    return false;
  }
}

proc channel.write(args ...?k,
                   style:iostyle,
                   out error:syserr):bool {
  if !writing then compilerError("write on read-only channel");
  error = ENOERR;
  on this.home {
    this.lock();
    var save_style = this._style();
    this._set_style(style);
    for param i in 1..k {
      if !error {
        error = _write_one_internal(_channel_internal, iokind.dynamic, args(i));
      }
    }
    this._set_style(save_style);
    this.unlock();
  }
  return !error;
}
proc channel.write(args ...?k,
                   style:iostyle):bool {
  var e:syserr = ENOERR;
  this.write((...args), style=style, error=e);
  if !e then return true;
  else {
    this._ch_ioerror(e, "in channel.write(" +
                        _args_to_proto((...args), preArg="") +
                        "style:iostyle)");
    return false;
  }
}

proc channel.writeln(out error:syserr):bool {
  return this.write(new ioNewline(), error=error);
}
proc channel.writeln():bool {
  return this.write(new ioNewline());
}
proc channel.writeln(args ...?k, out error:syserr):bool {
  return this.write((...args), new ioNewline(), error=error);
}
proc channel.writeln(args ...?k):bool {
  return this.write((...args), new ioNewline());
}
proc channel.writeln(args ...?k,
                     style:iostyle):bool {
  return this.write((...args), new ioNewline(), style=style);
}
proc channel.writeln(args ...?k,
                     style:iostyle,
                     out error:syserr):bool {
  return this.write((...args), new ioNewline(), style=style, error=error);
}

proc channel.flush(out error:syserr) {
  error = ENOERR;
  on this.home {
    error = qio_channel_flush(locking, _channel_internal);
  }
}
proc channel.flush() {
  var e:syserr = ENOERR;
  this.flush(error=e);
  if e then this._ch_ioerror(e, "in channel.flush");
}

proc channel.assertEOF(error:string) {
  if writing {
    this._ch_ioerror(EINVAL, "assertEOF on writing channel");
  } else {
    var tmp:uint(8);
    var err:syserr;
    this.read(tmp, error=err);
    if err != EEOF {
      this._ch_ioerror("assert failed", error);
    }
  }
}
proc channel.assertEOF() {
  this.assertEOF("- Not at EOF");
}

proc channel.close(out error:syserr) {
  error = ENOERR;
  on this.home {
    error = qio_channel_close(locking, _channel_internal);
  }
}

proc channel.close() {
  var e:syserr = ENOERR;
  this.close(error=e);
  if e then this._ch_ioerror(e, "in channel.close");
}

/*
proc channel.modifyStyle(f:func(iostyle, iostyle))
{
  on this.home {
    this.lock();
    var style = this._style();
    style = f(style);
    this._set_style(style);
    this.unlock();
  }
}
*/

record ItemReader {
  type ItemType;
  param kind:iokind;
  param locking:bool;
  var ch:channel(false,kind,locking);
  proc read(out arg:ItemType, out error:syserr):bool {
    return ch.read(arg, error=error);
  }
  proc read(out arg:ItemType):bool {
    return ch.read(arg);
  }

  iter these() {
    while true {
      var x:ItemType;
      var gotany = ch.read(x);
      if ! gotany then break;
      yield x;
    }
  }
  /* It would be nice to be able to handle errors
     when reading with these()
     but it's not clear how to get the error argument
     out. Exceptions would sort us out...
  iter these(out error:syserr) {
    while true {
      var x:ItemType;
      var gotany = ch.read(x, error=error);
      if ! gotany then break;
      yield x;
    }
  }*/
}

proc channel.itemReader(type ItemType, param kind:iokind=iokind.dynamic) {
  if writing then compilerError(".itemReader on write-only channel");
  return new ItemReader(ItemType, kind, locking, this);
}

record ItemWriter {
  type ItemType;
  param kind:iokind;
  param locking:bool;
  var ch:channel(false,kind);
  proc write(arg:ItemType, out error:syserr):bool {
    return ch.write(arg, error=error);
  }
  proc write(arg:ItemType):bool {
    return ch.write(arg);
  }
}

proc channel.itemWriter(type ItemType, param kind:iokind=iokind.dynamic) {
  if !writing then compilerError(".itemWriter on read-only channel");
  return new ItemWriter(ItemType, kind, locking, this);
}

// And now, the toplevel items.

const stdin:channel(false, iokind.dynamic, true) = openfd(0).reader(); 
const stdout:channel(true, iokind.dynamic, true) = openfp(chpl_cstdout()).writer(); 
const stderr:channel(true, iokind.dynamic, true) = openfp(chpl_cstderr()).writer(); 

proc write(args ...?n) {
  stdout.write((...args));
}
proc writeln(args ...?n) {
  stdout.writeln((...args));
}
proc writeln() {
  stdout.writeln();
}

proc read(inout args ...?n):bool {
  return stdin.read((...args));
}
proc readln(inout args ...?n):bool {
  return stdin.readln((...args));
}
proc readln():bool {
  return stdin.readln();
}

proc readln(type t ...?numTypes) {
  return stdin.readln((...t));
}
proc read(type t ...?numTypes) {
  return stdin.read((...t));
}

class ChannelWriter : Writer {
  var _channel_internal:qio_channel_ptr_t = QIO_CHANNEL_PTR_NULL;
  var err:syserr = ENOERR;
  proc binary:bool {
    var ret:uint(8);
    on this {
      ret = qio_channel_binary(_channel_internal);
    }
    return ret != 0;
  }
  proc styleElement(element:int):int {
    var ret:int = 0;
    on this {
      ret = qio_channel_style_element(_channel_internal, element);
    }
    return ret;
  }

  proc error():syserr {
    return err;
  }
  proc setError(e:syserr) {
    err = e;
  }
  proc clearError() {
    err = 0;
  }
  proc writePrimitive(x) {
    if !err {
      on this {
        err = _write_one_internal(_channel_internal, iokind.dynamic, x);
      }
    }
  }
  proc writeThis(w:Writer) {
    // MPF - I don't understand why I had to add this,
    // but without it test/modules/diten/returnClassDiffModule5.chpl fails.
    compilerError("writeThis on ChannelWriter called");
  }
  // writeThis + no readThis -> ChannelWriter itself cannot be read
}
class ChannelReader : Reader {
  var _channel_internal:qio_channel_ptr_t = QIO_CHANNEL_PTR_NULL;
  var err:syserr = ENOERR;
  proc binary:bool {
    var ret:uint(8);
    on this {
      ret = qio_channel_binary(_channel_internal);
    }
    return ret != 0;
  }
  proc styleElement(element:int):int {
    var ret:int = 0;
    on this {
      ret = qio_channel_style_element(_channel_internal, element);
    }
    return ret;
  }

  proc error():syserr {
    return err;
  }
  proc setError(e:syserr) {
    err = e;
  }
  proc clearError() {
    err = ENOERR;
  }
  proc readPrimitive(inout x:?t) where _isIoPrimitiveTypeOrNewline(t) {
    if !err {
      on this {
        err = _read_one_internal(_channel_internal, iokind.dynamic, x);
      }
    }
  }
  proc writeThis(w:Writer) {
    compilerError("writeThis on ChannelReader called");
  }
  // writeThis + no readThis -> ChannelReader itself cannot be read
}

// Delete a file.
proc unlink(path:string, out error:syserr) {
  extern proc sys_unlink(path:string):err_t;
  error = sys_unlink(path);
}
proc unlink(path:string) {
  var err:syserr = ENOERR;
  unlink(path, err);
  if err then ioerror(err, "in unlink", path);
}

proc unicodeSupported():bool {
  extern proc qio_unicode_supported():c_int;
  return qio_unicode_supported() > 0;
}

inline
proc _toIntegral(x:?t) where _isIntegralType(t)
{
  return (x, true);
}
inline
proc _toIntegral(x:?t) where _isIoPrimitiveType(t) && !_isIntegralType(t)
{
  return (x:int, true);
}
inline
proc _toIntegral(x:?t) where !_isIoPrimitiveType(t)
{
  return (0, false);
}

inline
proc _toSigned(x:?t) where _isSignedType(t)
{
  return (x, true);
}
inline
proc _toSigned(x:uint(8))
{
  return (x:int(8), true);
}
inline
proc _toSigned(x:uint(16))
{
  return (x:int(16), true);
}
inline
proc _toSigned(x:uint(32))
{
  return (x:int(32), true);
}
inline
proc _toSigned(x:uint(64))
{
  return (x:int(64), true);
}

inline
proc _toSigned(x:?t) where _isIoPrimitiveType(t) && !_isIntegralType(t)
{
  return (x:int, true);
}
inline
proc _toSigned(x:?t) where !_isIoPrimitiveType(t)
{
  return (0:int, false);
}

inline
proc _toUnsigned(x:?t) where _isUnsignedType(t)
{
  return (x, true);
}
inline
proc _toUnsigned(x:int(8))
{
  return (x:uint(8), true);
}
inline
proc _toUnsigned(x:int(16))
{
  return (x:uint(16), true);
}
inline
proc _toUnsigned(x:int(32))
{
  return (x:uint(32), true);
}
inline
proc _toUnsigned(x:int(64))
{
  return (x:uint(64), true);
}


inline
proc _toUnsigned(x:?t) where _isIoPrimitiveType(t) && !_isIntegralType(t)
{
  return (x:uint, true);
}
inline
proc _toUnsigned(x:?t) where !_isIoPrimitiveType(t)
{
  return (0:uint, false);
}


inline
proc _toReal(x:?t) where _isRealType(t)
{
  return (x, true);
}
inline
proc _toReal(x:?t) where _isIoPrimitiveType(t) && !_isRealType(t)
{
  return (x:real, true);
}
inline
proc _toReal(x:?t) where !_isIoPrimitiveType(t)
{
  return (0.0, false);
}

inline
proc _toImag(x:?t) where _isImagType(t)
{
  return (x, true);
}
inline
proc _toImag(x:?t) where _isIoPrimitiveType(t) && !_isImagType(t)
{
  return (x:imag, true);
}
inline
proc _toImag(x:?t) where !_isIoPrimitiveType(t)
{
  return (0.0i, false);
}


inline
proc _toComplex(x:?t) where _isComplexType(t)
{
  return (x, true);
}
inline
proc _toComplex(x:?t) where _isIoPrimitiveType(t) && !_isComplexType(t)
{
  return (x:complex, true);
}
inline
proc _toComplex(x:?t) where !_isIoPrimitiveType(t)
{
  return (0.0+0.0i, false);
}

inline
proc _toRealOrComplex(x:?t) where _isComplexType(t)
{
  return (x, true);
}
inline
proc _toRealOrComplex(x:?t) where _isFloatType(t)
{
  return (x, true);
}
inline
proc _toRealOrComplex(x:?t) where _isIoPrimitiveType(t) && !_isComplexType(t) && !_isFloatType(t)
{
  return (x:real, true);
}
inline
proc _toRealOrComplex(x:?t) where !_isIoPrimitiveType(t)
{
  return (0.0, false);
}

proc _isNumericType(type t) param return
_isIntegralType(t) || _isRealType(t) || _isImagType(t) || _isComplexType(t);

inline
proc _toNumeric(x:?t) where _isNumericType(t)
{
  return (x, true);
}
inline
proc _toNumeric(x:?t) where _isIoPrimitiveType(t) && !_isNumericType(t)
{
  // enums, bools get cast to int.
  return (x:int, true);
}
inline
proc _toNumeric(x:?t) where !_isIoPrimitiveType(t)
{
  return (0, false);
}



inline
proc _toString(x:?t) where _isIoPrimitiveType(t)
{
  return (x:string, true);
}
inline
proc _toString(x:?t) where !_isIoPrimitiveType(t)
{
  return ("", false);
}

inline
proc _toChar(x:?t) where _isIntegralType(t)
{
  return (x:int(32), true);
}
inline
proc _toChar(x:?t) where t == string
{
  var chr:int(32);
  var nbytes:c_int;
  qio_decode_char_buf(chr, nbytes, x, x.length);
  return (chr, true);
}
inline
proc _toChar(x:?t) where !(t==string || _isIntegralType(t))
{
  return (0:int(32), false);
}


// If we wanted to give ERANGE if (for example
// var x:int(8); readf("%i", x);
// was given the input 1000, this would be the place to do it.
inline
proc _setIfPrimitive(ref lhs:?t, rhs:?t2, argi:int):syserr where t==bool&&_isIoPrimitiveType(t2)
{
  var empty:t2;
  if rhs == empty {
    lhs = false;
  } else {
    lhs = true;
  }
  return ENOERR;
}
inline
proc _setIfPrimitive(ref lhs:?t, rhs:?t2, argi:int):syserr where t!=bool&&_isIoPrimitiveType(t)
{
  //stdout.writeln("setIfPrimitive ", lhs, " ", rhs);
  lhs = rhs:t;
  return ENOERR;
}
inline
proc _setIfPrimitive(ref lhs:?t, rhs, argi:int):syserr where !_isIoPrimitiveType(t)
{
  return qio_format_error_arg_mismatch(argi);
}

inline
proc _setIfChar(ref lhs:?t, rhs:int(32)) where t == string
{
  lhs = new ioChar(rhs):string;
}
inline
proc _setIfChar(ref lhs:?t, rhs:int(32)) where _isIntegralType(t)
{
  lhs = rhs:t;
}
inline
proc _setIfChar(ref lhs:?t, rhs:int(32)) where !(t==string||_isIntegralType(t))
{
  // do nothing
}



inline
proc _toRegexp(x:?t) where t == regexp
{
  return (x, true);
}
inline
proc _toRegexp(x:?t) where t != regexp
{
  var r:regexp;
  return (r, false);
}

param _format_debug = false;

class _channel_regexp_info {
  var hasRegexp = false;
  var matchedRegexp = false;
  var releaseRegexp = false;
  var theRegexp = qio_regexp_null();
  var matches: _ddata(qio_regexp_string_piece_t) = nil; // size = ncaptures+1
  var capArr: _ddata(string) = nil; // size = ncaptures
  var capturei: int;
  var ncaptures: int;
  proc clear() {
    if releaseRegexp {
      qio_regexp_release(theRegexp);
    }
    theRegexp = qio_regexp_null();
    hasRegexp = false;
    matchedRegexp = false;
    releaseRegexp = false;
    if matches then _ddata_free(matches);
    for i in 0..#ncaptures do capArr[i] = "";
    if capArr then _ddata_free(capArr);
  }
  proc allocate_captures() {
    ncaptures = qio_regexp_get_ncaptures(theRegexp);
    matches = _ddata_allocate(qio_regexp_string_piece_t, ncaptures+1);
    capArr = _ddata_allocate(string, ncaptures);
    capturei = 0;
  }
  proc ~_channel_regexp_info() {
    clear();
  }
}

proc channel._match_regexp_if_needed(cur:size_t, len:size_t, ref error:syserr, ref style:iostyle, r:_channel_regexp_info)
{
  if _format_debug then stdout.writeln("REGEXP MATCH ENTRY");
  if qio_regexp_ok(r.theRegexp) {
    if r.matchedRegexp then return;
    if _format_debug then stdout.writeln("REGEXP MATCH");
    r.matchedRegexp = true;
    r.allocate_captures(); // also allocates matches and capArr
    var ncaps = r.ncaptures;
    var nm = ncaps + 1;
    var maxlen:int(64) = style.max_width_characters;
    // If we are working on the last part of the format string,
    // and there is a match, we can immediately discard
    // data before any captures in the match (or if there
    // are no captures - the entire match).
    var can_discard = (cur == len);
    if maxlen == max(uint(32)) then maxlen = max(int(64));
    var before_match = qio_channel_offset_unlocked(_channel_internal);
    // Do the actual regexp search.
    // Now read, matching the regexp.
    error = qio_regexp_channel_match(r.theRegexp, false, _channel_internal,
                                     maxlen, QIO_REGEXP_ANCHOR_START,
                                     can_discard,
                                     /* keep_unmatched */ true,
                                     /* keep_whole_pattern */ false,
                                     r.matches, nm);
    var after_match = qio_channel_offset_unlocked(_channel_internal);

    // Now, if there was no match, error=EFORMAT
    // if there was a match, error = no error
    // Either way, we have to handle the next several
    // arguments as capture groups.
    if ! error {
      for j in 0..#ncaps {
        // matches[0] is the whole pattern, and
        // we only want to extract capture groups.
        var m = _to_reMatch(r.matches[1+j]);
        _extractMatch(m, r.capArr[j], error);
        if error then break;
      }
      // And, advance the channel to the end of the match.
      var cur = qio_channel_offset_unlocked(_channel_internal);
      var target = r.matches[0].offset + r.matches[0].len;
      error = qio_channel_advance(false, _channel_internal, target - cur);
      if error {
        if _format_debug then stdout.writeln("TODO AQB");
      }
    } else {
      // otherwise, clear out caps...
      for j in 0..#ncaps {
        r.capArr[j] = "";
      }
      // ... and put the channel before the match.
      var cur = qio_channel_offset_unlocked(_channel_internal);
      qio_channel_advance(false, _channel_internal, before_match - cur);
      // EFORMAT means the pattern did not match.
      if _format_debug then stdout.writeln("TODO AQZ");
    }
  } else {
    error = qio_format_error_bad_regexp();;
    if _format_debug then stdout.writeln("TODO AZB");
  }
}

// Reads the next format string that will require argument handling.
// Handles literals and regexps itself; everything else will
// be returned in conv and with gotConv = true.
// Assumes, for a reading channel, that we are withn a mark/revert/commit
//  in readf. (used in the regexp handling here).
proc channel._format_reader(
    fmt:string, ref cur:size_t, len:size_t, ref error:syserr,
    ref conv:qio_conv_t, ref gotConv:bool, ref style:iostyle,
    ref r:_channel_regexp_info,
    isReadf:bool)
{
  if _format_debug then stdout.writeln("FORMAT READER ENTRY");
  if r != nil then r.hasRegexp = false;
  if !error {
    while cur < len {
      gotConv = false;
      if error then break;
      if _format_debug then stdout.writeln("TOP OF LOOP cur=", cur, " len=", len);
      var end:size_t;
      error = qio_conv_parse(fmt, cur, end, isReadf, conv, style);
      if error {
        if _format_debug then stdout.writeln("TODO ACC");
      }
      cur = end;
      if error then break;
      if _format_debug then stdout.writeln("MIDDLE OF LOOP");
      if conv.argType == QIO_CONV_ARG_TYPE_NONE_LITERAL {
        // Print whitespace or I/O literal.
        // literal string in conv
        if isReadf {
          // Scan whitespace or I/O literal.
          // literal string in conv
          if conv.literal_is_whitespace == 2 {
            if _format_debug then stdout.writeln("NEWLINE");
            // Handle a \n newline in the format string.
            // Other space.
            var offsetA = qio_channel_offset_unlocked(_channel_internal);
            error = qio_channel_skip_past_newline(false, _channel_internal, true);
            var offsetB = qio_channel_offset_unlocked(_channel_internal);
            if (!error) && offsetA == offsetB {
              // didn't really read newline.
              error = EFORMAT;
            }
            if _format_debug then stdout.writeln("AFTER NEWLINE err is ", error:int);
          } else if conv.literal_is_whitespace == 1 {
            if _format_debug then stdout.writeln("WHITESPACE");
            // Other space.
            var offsetA = qio_channel_offset_unlocked(_channel_internal);
            error = qio_channel_scan_literal_2(false, _channel_internal, conv.literal, 0, true);
            if _format_debug {
             if error then stdout.writeln("TODO XZOB");
            }
            var offsetB = qio_channel_offset_unlocked(_channel_internal);
            if (!error) && offsetA == offsetB {
              // didn't really read whitespace.
              error = EFORMAT;
            }
          } else {
            error = qio_channel_scan_literal_2(false, _channel_internal, conv.literal, conv.literal_length, false);
          }
        } else {
          // when printing we don't care if it's just whitespace.
          error = qio_channel_print_literal_2(false, _channel_internal, conv.literal, conv.literal_length);
        }
      } else if conv.argType == QIO_CONV_ARG_TYPE_NONE_REGEXP_LITERAL {
        if ! isReadf {
          // It's not so clear what to do when printing
          // a regexp. So we just don't handle it.
          error = qio_format_error_write_regexp();
          if _format_debug then stdout.writeln("TODO AZA");
        } else {
          // allocate regexp info if needed
          if r == nil then r = new _channel_regexp_info();
          // clear out old data, if there is any.
          r.clear();
          // Compile a regexp from the format string
          var errstr:string;
          if _format_debug then stdout.writeln("COMPILING REGEXP");
          // build a regexp out of regexp and regexp_flags
          qio_regexp_create_compile_flags_2(conv.regexp, conv.regexp_length, conv.regexp_flags, conv.regexp_flags_length, /* utf8? */ true, r.theRegexp);
          r.releaseRegexp = true;
          if qio_regexp_ok(r.theRegexp) {
            r.hasRegexp = true;
            r.ncaptures = qio_regexp_get_ncaptures(r.theRegexp);
            // If there are no captures, and we don't have arguments
            // to consume, go ahead and match the regexp.
            if r.ncaptures > 0 ||
               conv.preArg1 != QIO_CONV_UNK ||
               conv.preArg2 != QIO_CONV_UNK ||
               conv.preArg3 != QIO_CONV_UNK
            {
              // We need to consume args as part of matching this regexp. 
              gotConv = true;
              break;
            } else {
              // No args will be consumed.
              _match_regexp_if_needed(cur, len, error, style, r);
            }
          } else {
            error = qio_format_error_bad_regexp();
            if _format_debug then stdout.writeln("TODO AZB");
            //if dieOnError then assert(!error, errstr);
          }
        }
      } else {
        // Some other kind of format specifier... we
        // will return to handle.
        gotConv = true;
        break;
      }
    }
  }
}

proc channel._conv_helper(
    ref error:syserr,
    ref conv:qio_conv_t, ref gotConv:bool,
    ref j:int,
    ref argType)
{
  if error then return;
  if gotConv {
    // Perhaps we need to handle pre/post args
    // that adjust the style
    if conv.preArg1 != QIO_CONV_UNK {
      argType(j) = conv.preArg1;
      j += 1;
    }
    if conv.preArg2 != QIO_CONV_UNK {
      argType(j) = conv.preArg2;
      j += 1;
    }
    if conv.preArg3 != QIO_CONV_UNK {
      argType(j) = conv.preArg3;
      j += 1;
    }
    if conv.argType != QIO_CONV_UNK {
      if argType(j) == QIO_CONV_UNK {
        // Some regexp paths set it earlier..
        argType(j) = conv.argType;
      }
      j += 1;
    }
  }
}

proc channel._conv_sethandler(
    ref error:syserr,
    argtypei:c_int,
    ref style:iostyle,
    i:int, argi,
    isReadf:bool):bool
{
  if error then return false;
  // Now, set style elements based on action
  // at i
  select argtypei {
    when QIO_CONV_SET_MIN_WIDTH_COLS {
      var (t,ok) = _toIntegral(argi);
      if ! ok {
        error = qio_format_error_arg_mismatch(i);
        if _format_debug then stdout.writeln("TODO AZE");
      } else style.min_width_columns = t:uint(32);
    }
    when QIO_CONV_SET_MAX_WIDTH_COLS {
      var (t,ok) = _toIntegral(argi);
      if ! ok {
        error = qio_format_error_arg_mismatch(i);
        if _format_debug then stdout.writeln("TODO AZF");
      } else style.max_width_columns = t:uint(32);
    }
    when QIO_CONV_SET_MAX_WIDTH_CHARS {
      var (t,ok) = _toIntegral(argi);
      if ! ok {
        error = qio_format_error_arg_mismatch(i);
        if _format_debug then stdout.writeln("TODO AZG");
      } else style.max_width_characters = t:uint(32);
    }
    when QIO_CONV_SET_MAX_WIDTH_BYTES {
      var (t,ok) = _toIntegral(argi);
      if ! ok {
        error = qio_format_error_arg_mismatch(i);
        if _format_debug then stdout.writeln("TODO AZGX");
      } else style.max_width_bytes = t:uint(32);
    }
    when QIO_CONV_SET_PRECISION {
      var (t,ok) = _toIntegral(argi);
      if ! ok {
        error = qio_format_error_arg_mismatch(i);
        if _format_debug then stdout.writeln("TODO AZH");
      } else style.precision = t:int(32);
    }
    when QIO_CONV_SET_STRINGSTART {
      var (t,ok) = _toChar(argi);
      if ! ok {
        error = qio_format_error_arg_mismatch(i);
        if _format_debug then stdout.writeln("TODO AZH");
      } else style.string_start = t:style_char_t;
    }
    when QIO_CONV_SET_STRINGEND {
      var (t,ok) = _toChar(argi);
      if ! ok {
        error = qio_format_error_arg_mismatch(i);
        if _format_debug then stdout.writeln("TODO AZH");
      } else style.string_end = t:style_char_t;
    }
    when QIO_CONV_SET_STRINGSTARTEND {
      var (t,ok) = _toChar(argi);
      if ! ok {
        error = qio_format_error_arg_mismatch(i);
        if _format_debug then stdout.writeln("TODO AZH");
      } else {
        style.string_start = t:style_char_t;
        style.string_end = t:style_char_t;
      }
    }
    when QIO_CONV_SET_STRINGLEN {
      var (t,ok) = _toIntegral(argi);
      if ! ok {
        error = qio_format_error_arg_mismatch(i);
        if _format_debug then stdout.writeln("TODO AZH");
      } else {
        style.str_style = t:int(64);
      }
    }
    when QIO_CONV_SET_TERMINATOR {
      var (t,ok) = _toChar(argi);
      if ! ok {
        error = qio_format_error_arg_mismatch(i);
        if _format_debug then stdout.writeln("TODO AZH");
      } else {
        style.str_style = stringStyleTerminated(t:uint(8));
      }
    }
    when QIO_CONV_SET_DONE {
      // Do nothing. Already handled.
    }
    when QIO_CONV_UNK {
      // Too many arguments.
      error = qio_format_error_too_many_args();
      if _format_debug then stdout.writeln("TODO AZK");
    } otherwise {
      return true;
    }
  }
  return false;
}

proc channel._write_signed(width:uint(32), t:int, i:int)
{
  var error:syserr;
  var byteorder = qio_channel_byteorder(_channel_internal);
  select width {
    when 1 {
      var x = t:int(8);
      error = qio_channel_write_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
    } when 2 {
      var x = t:int(16);
      error = qio_channel_write_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
    } when 4 {
      var x = t:int(32);
      error = qio_channel_write_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
    } when 8 {
      var x = t:int(64);
      error = qio_channel_write_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
    } otherwise error = qio_format_error_arg_mismatch(i);
  }
  return error;
}

proc channel._read_signed(width:uint(32), out t:int, i:int)
{
  var error:syserr;
  var byteorder = qio_channel_byteorder(_channel_internal);
  select width {
    when 1 {
      var x:int(8);
      error = qio_channel_read_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
      t = x;
    } when 2 {
      var x:int(16);
      error = qio_channel_read_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
      t = x;
    } when 4 {
      var x:int(32);
      error = qio_channel_read_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
      t = x;
    } when 8 {
      var x:int(64);
      error = qio_channel_read_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
      t = x;
    } otherwise error = qio_format_error_arg_mismatch(i);
  }
  return error;
}

proc channel._write_unsigned(width:uint(32), t:uint, i:int)
{
  var error:syserr;
  var byteorder = qio_channel_byteorder(_channel_internal);
  select width {
    when 1 {
      var x = t:uint(8);
      error = qio_channel_write_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
    } when 2 {
      var x = t:uint(16);
      error = qio_channel_write_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
    } when 4 {
      var x = t:uint(32);
      error = qio_channel_write_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
    } when 8 {
      var x = t:uint(64);
      error = qio_channel_write_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
    } otherwise error = qio_format_error_arg_mismatch(i);
  }
  return error;
}
proc channel._read_unsigned(width:uint(32), out t:uint, i:int)
{
  var error:syserr;
  var byteorder = qio_channel_byteorder(_channel_internal);
  select width {
    when 1 {
      var x:uint(8);
      error = qio_channel_read_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
      t = x;
    } when 2 {
      var x:uint(16);
      error = qio_channel_read_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
      t = x;
    } when 4 {
      var x:uint(32);
      error = qio_channel_read_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
      t = x;
    } when 8 {
      var x:uint(64);
      error = qio_channel_read_int(false, byteorder, _channel_internal, x, numBytes(x.type), _isSignedType(x.type));
      t = x;
    } otherwise error = qio_format_error_arg_mismatch(i);
  }
  return error;
}


proc channel._write_real(width:uint(32), t:real, i:int)
{
  var error:syserr;
  var byteorder = qio_channel_byteorder(_channel_internal);
  select width {
    when 4 {
      var x = t:real(32);
      error = qio_channel_write_float(false, byteorder, _channel_internal, x, numBytes(x.type));
    } when 8 {
      var x = t:real(64);
      error = qio_channel_write_float(false, byteorder, _channel_internal, x, numBytes(x.type));
    } otherwise error = qio_format_error_arg_mismatch(i);
  }
  return error;
}
proc channel._read_real(width:uint(32), out t:real, i:int)
{
  var error:syserr;
  var byteorder = qio_channel_byteorder(_channel_internal);
  select width {
    when 4 {
      var x:real(32);
      error = qio_channel_read_float(false, byteorder, _channel_internal, x, numBytes(x.type));
      t = x;
    } when 8 {
      var x:real(64);
      error = qio_channel_read_float(false, byteorder, _channel_internal, x, numBytes(x.type));
      t = x;
    } otherwise error = qio_format_error_arg_mismatch(i);
  }
  return error;
}


proc channel._write_complex(width:uint(32), t:complex, i:int)
{
  var error:syserr;
  var byteorder = qio_channel_byteorder(_channel_internal);
  select width {
    when 8 {
      var x = t:complex(64);
      var re = x.re;
      var im = x.im;
      error = qio_channel_write_complex(false,byteorder,_channel_internal,re,im, numBytes(re.type));
    } when 16 {
      var x = t:complex(128);
      var re = x.re;
      var im = x.im;
      error = qio_channel_write_complex(false,byteorder,_channel_internal,re,im, numBytes(re.type));
    } otherwise error = qio_format_error_arg_mismatch(i);
  }
  return error;
}

proc channel._read_complex(width:uint(32), out t:complex, i:int)
{
  var error:syserr;
  var byteorder = qio_channel_byteorder(_channel_internal);
  select width {
    when 8 {
      var x:complex(64);
      var re:x.re.type;
      var im:x.im.type;
      error = qio_channel_read_complex(false,byteorder,_channel_internal,re,im, numBytes(re.type));
      x = (re, im):complex(64); // tuple to complex
      t = x;
    } when 16 {
      var x:complex(128);
      var re:x.re.type;
      var im:x.im.type;
      error = qio_channel_read_complex(false,byteorder,_channel_internal,re,im, numBytes(re.type));
      x = (re, im):complex(128); // tuple to complex
      t = x;
    } otherwise error = qio_format_error_arg_mismatch(i);
  }
  return error;
}



// 1st arg is format string
proc channel.writef(fmt:string, args ...?k, out error:syserr):bool {
  if !writing then compilerError("writef on read-only channel");
  error = ENOERR;
  on this.home {
    this.lock();
    var save_style = this._style();
    var cur:size_t = 0;
    var len:size_t = fmt.length:size_t;
    var conv:qio_conv_t;
    var gotConv:bool;
    var style:iostyle;
    var end:size_t;
    var argType:(k+5)*c_int;

    var r:_channel_regexp_info = nil;

    for i in 1..argType.size {
      argType(i) = QIO_CONV_UNK;
    }

    var j = 1;

    for param i in 1..k {
      // The inside of this loop is a bit crazy because
      // we're writing it all in a param for in order to
      // get generic argument handling.

      gotConv = false;

      if j <= i {
        _format_reader(fmt, cur, len, error,
                       conv, gotConv, style, r,
                       false);
      }

      _conv_helper(error, conv, gotConv, j, argType);

      var domore = _conv_sethandler(error, argType(i), style, i,args(i),false);

      if _format_debug then writeln("domore ", domore, " arg ", argType(i), " arg ", args(i));

      if domore {
        this._set_style(style);
        // otherwise we will consume at least one argument.
        select argType(i) {
          when QIO_CONV_ARG_TYPE_SIGNED, QIO_CONV_ARG_TYPE_BINARY_SIGNED {
            var (t,ok) = _toSigned(args(i));
            if ! ok {
              error = qio_format_error_arg_mismatch(i);
              if _format_debug then stdout.writeln("TODO AZK");
            } else {
              if argType(i) == QIO_CONV_ARG_TYPE_BINARY_SIGNED then
                error = _write_signed(style.max_width_bytes, t, i);
              else
                error = _write_one_internal(_channel_internal, iokind.dynamic, t);
            }
          } when QIO_CONV_ARG_TYPE_UNSIGNED, QIO_CONV_ARG_TYPE_BINARY_UNSIGNED {
            var (t,ok) = _toUnsigned(args(i));
            if ! ok {
              error = qio_format_error_arg_mismatch(i);
              if _format_debug then stdout.writeln("TODO AZK");
            } else {
              if argType(i) == QIO_CONV_ARG_TYPE_BINARY_UNSIGNED then
                error = _write_unsigned(style.max_width_bytes, t, i);
              else
                error = _write_one_internal(_channel_internal, iokind.dynamic, t);
            }
          } when QIO_CONV_ARG_TYPE_REAL, QIO_CONV_ARG_TYPE_BINARY_REAL {
            var (t,ok) = _toReal(args(i));
            if ! ok {
              error = qio_format_error_arg_mismatch(i);
              if _format_debug then stdout.writeln("TODO AZK");
            } else {
              if argType(i) == QIO_CONV_ARG_TYPE_BINARY_REAL then
                error = _write_real(style.max_width_bytes, t, i);
              else
                error = _write_one_internal(_channel_internal, iokind.dynamic, t);
            }
          } when QIO_CONV_ARG_TYPE_IMAG, QIO_CONV_ARG_TYPE_BINARY_IMAG {
            var (t,ok) = _toImag(args(i));
            if ! ok {
              error = qio_format_error_arg_mismatch(i);
              if _format_debug then stdout.writeln("TODO AZK");
            } else {
              if argType(i) == QIO_CONV_ARG_TYPE_BINARY_IMAG then
                error = _write_real(style.max_width_bytes, t:real, i);
              else
                error = _write_one_internal(_channel_internal, iokind.dynamic, t);
            }
          } when QIO_CONV_ARG_TYPE_COMPLEX, QIO_CONV_ARG_TYPE_BINARY_COMPLEX {
            var (t,ok) = _toComplex(args(i));
            if ! ok {
              error = qio_format_error_arg_mismatch(i);
              if _format_debug then stdout.writeln("TODO AZK");
            } else {
              if argType(i) == QIO_CONV_ARG_TYPE_BINARY_COMPLEX then
                error = _write_complex(style.max_width_bytes, t, i);
              else error = _write_one_internal(_channel_internal, iokind.dynamic, t);
            }
          } when QIO_CONV_ARG_TYPE_NUMERIC {
            var (t,ok) = _toNumeric(args(i));
            if ! ok {
              error = qio_format_error_arg_mismatch(i);
              if _format_debug then stdout.writeln("TODO AZO11");
            } else error = _write_one_internal(_channel_internal, iokind.dynamic, t);
          } when QIO_CONV_ARG_TYPE_CHAR {
            var (t,ok) = _toChar(args(i));
            if ! ok {
              error = qio_format_error_arg_mismatch(i);
              if _format_debug then stdout.writeln("TODO AZN");
            } else error = _write_one_internal(_channel_internal, iokind.dynamic, new ioChar(t));
          } when QIO_CONV_ARG_TYPE_STRING {
            var (t,ok) = _toString(args(i));
            if ! ok {
              error = qio_format_error_arg_mismatch(i);
              if _format_debug then stdout.writeln("TODO AZO");
            } else error = _write_one_internal(_channel_internal, iokind.dynamic, t);
          } when QIO_CONV_ARG_TYPE_REGEXP {
            // It's not so clear what to do when printing
            // a regexp. So we just don't handle it.
            error = qio_format_error_write_regexp();
            if _format_debug then stdout.writeln("TODO AZP");
          } when QIO_CONV_ARG_TYPE_REPR {
            error = _write_one_internal(_channel_internal, iokind.dynamic, args(i));
          } otherwise {
            // Unhandled argument type!
            halt("readf/writef internal error ", argType(i));
          }
        }
      }
    }

    if ! error {
      if cur < len {
        var dummy:c_int;
        _format_reader(fmt, cur, len, error,
                       conv, gotConv, style, r,
                       false);
      }

      if cur < len {
        // Mismatched number of arguments!
        error = qio_format_error_too_few_args();
        if _format_debug then stdout.writeln("TODO AZR");
      }
    }

    this._set_style(save_style);
    this.unlock();
  }
  return !error;
}
proc channel.writef(fmt:string, out error:syserr):bool {
  if !writing then compilerError("writef on read-only channel");
  error = ENOERR;
  on this.home {
    this.lock();
    var save_style = this._style();
    var cur:size_t = 0;
    var len:size_t = fmt.length:size_t;
    var conv:qio_conv_t;
    var gotConv:bool;
    var style:iostyle;
    var end:size_t;
    var dummy:c_int;

    var r:_channel_regexp_info = nil;

    _format_reader(fmt, cur, len, error,
                   conv, gotConv, style, r,
                   false);

    if ! error {
      if gotConv {
        error = qio_format_error_too_few_args();
        if _format_debug then stdout.writeln("TODO AZZs");
      }
    }

    if ! error {
      if cur < len {
        // Mismatched number of arguments!
        error = qio_format_error_too_few_args();
        if _format_debug then stdout.writeln("TODO AZS");
      }
    }

    this._set_style(save_style);
    this.unlock();
  }
  return !error;
}

proc channel.readf(fmt:string, ref args ...?k, out error:syserr):bool {
  if writing then compilerError("readf on write-only channel");
  error = ENOERR;
  on this.home {
    this.lock();
    var save_style = this._style();
    var cur:size_t = 0;
    var len:size_t = fmt.length:size_t;
    var conv:qio_conv_t;
    var gotConv:bool;
    var style:iostyle;
    var end:size_t;
    var argType:(k+5)*c_int;

    var r:_channel_regexp_info = nil;

    for i in 1..argType.size {
      argType(i) = QIO_CONV_UNK;
    }

    error = qio_channel_mark(false, _channel_internal);
    if !error {
      var j = 1;

      for param i in 1..k {
        // The inside of this loop is a bit crazy because
        // we're writing it all in a param for in order to
        // get generic argument handling.
        if j <= i {
          _format_reader(fmt, cur, len, error,
                         conv, gotConv, style, r,
                         true);

          if r != nil && r.hasRegexp {
            // We need to handle the next ncaptures arguments.
            if i + r.ncaptures - 1 > k {
              error = qio_format_error_too_few_args();
              if _format_debug then stdout.writeln("TODO AXA");
            }
            for z in 0..#r.ncaptures {
              if i+z <= argType.size {
                argType(i+z) = QIO_CONV_SET_CAPTURE;
              }
            }
          }
        }

        _conv_helper(error, conv, gotConv, j, argType);

        var domore = _conv_sethandler(error, argType(i),style,i,args(i),false);

        if domore {
          this._set_style(style);
          // otherwise we will consume at least one argument.
          select argType(i) {
            when QIO_CONV_ARG_TYPE_SIGNED, QIO_CONV_ARG_TYPE_BINARY_SIGNED {
              var (t,ok) = _toSigned(args(i));
              if ! ok {
                error = qio_format_error_arg_mismatch(i);
                if _format_debug then stdout.writeln("TODO AXB");
              } else {
                var ti:int;
                if argType(i) == QIO_CONV_ARG_TYPE_BINARY_SIGNED then
                  error = _read_signed(style.max_width_bytes, ti, i);
                else
                  error = _read_one_internal(_channel_internal, iokind.dynamic, ti);
                if ! error then error = _setIfPrimitive(args(i),ti,i);
              }
            }
            when QIO_CONV_ARG_TYPE_UNSIGNED, QIO_CONV_ARG_TYPE_BINARY_UNSIGNED {
              var (t,ok) = _toUnsigned(args(i));
              if ! ok {
                error = qio_format_error_arg_mismatch(i);
                if _format_debug then stdout.writeln("TODO AXB");
              } else {
                var ti:uint;
                if argType(i) == QIO_CONV_ARG_TYPE_BINARY_UNSIGNED then
                  error = _read_unsigned(style.max_width_bytes, ti, i);
                else
                  error = _read_one_internal(_channel_internal, iokind.dynamic, ti);
                if ! error then error = _setIfPrimitive(args(i),ti,i);
              }
            } when QIO_CONV_ARG_TYPE_REAL, QIO_CONV_ARG_TYPE_BINARY_REAL {
              var (t,ok) = _toReal(args(i));
              if ! ok {
                error = qio_format_error_arg_mismatch(i);
                if _format_debug then stdout.writeln("TODO AXB");
              } else {
                var ti:real;
                if argType(i) == QIO_CONV_ARG_TYPE_BINARY_REAL then
                  error = _read_real(style.max_width_bytes, ti, i);
                else
                  error = _read_one_internal(_channel_internal, iokind.dynamic, ti);
                if ! error then error = _setIfPrimitive(args(i),ti,i);
              }
            } when QIO_CONV_ARG_TYPE_IMAG, QIO_CONV_ARG_TYPE_BINARY_IMAG {
              var (t,ok) = _toImag(args(i));
              if ! ok {
                error = qio_format_error_arg_mismatch(i);
                if _format_debug then stdout.writeln("TODO AXB1");
              } else {
                var ti:imag;
                if argType(i) == QIO_CONV_ARG_TYPE_BINARY_IMAG {
                  var tr:real;
                  error = _read_real(style.max_width_bytes, tr, i);
                  ti = tr:imag;
                } else
                  error = _read_one_internal(_channel_internal, iokind.dynamic, ti);
                if ! error then error = _setIfPrimitive(args(i),ti,i);
              }
            } when QIO_CONV_ARG_TYPE_COMPLEX, QIO_CONV_ARG_TYPE_BINARY_COMPLEX {
              var (t,ok) = _toComplex(args(i));
              if ! ok {
                error = qio_format_error_arg_mismatch(i);
                if _format_debug then stdout.writeln("TODO AXB");
              } else {
                var ti:complex;
                if argType(i) == QIO_CONV_ARG_TYPE_BINARY_COMPLEX then
                 error = _read_complex(style.max_width_bytes, ti, i);
                else
                  error = _read_one_internal(_channel_internal, iokind.dynamic, ti);
                if ! error then error = _setIfPrimitive(args(i),ti,i);
              }
            } when QIO_CONV_ARG_TYPE_NUMERIC {
              var (t,ok) = _toNumeric(args(i));
              if ! ok {
                error = qio_format_error_arg_mismatch(i);
                if _format_debug then stdout.writeln("TODO AXB1");
              } else {
                var ti = t;
                error = _read_one_internal(_channel_internal, iokind.dynamic, ti);
                if ! error then error = _setIfPrimitive(args(i),ti,i);
              }
            } when QIO_CONV_ARG_TYPE_CHAR {
              var (t,ok) = _toChar(args(i));
              var chr = new ioChar(t);
              if ! ok {
                error = qio_format_error_arg_mismatch(i);
                if _format_debug then stdout.writeln("TODO AXE");
              } else error = _read_one_internal(_channel_internal, iokind.dynamic, chr);
              if ! error then _setIfChar(args(i),chr.ch);
            } when QIO_CONV_ARG_TYPE_STRING {
              var (t,ok) = _toString(args(i));
              if ! ok {
                error = qio_format_error_arg_mismatch(i);
                if _format_debug then stdout.writeln("TODO AXF");
              }
              else error = _read_one_internal(_channel_internal, iokind.dynamic, t);
              if ! error then error = _setIfPrimitive(args(i),t,i);
            } when QIO_CONV_ARG_TYPE_REGEXP {
              var (t,ok) = _toRegexp(args(i));
              if ! ok {
                error = qio_format_error_arg_mismatch(i);
                if _format_debug then stdout.writeln("TODO AXG");
              }
              // match it here.
              if r == nil then r = new _channel_regexp_info();
              r.clear();
              r.theRegexp = t._regexp;
              r.hasRegexp = true;
              r.releaseRegexp = false;
              _match_regexp_if_needed(cur, len, error, style, r);

              // Set the capture groups.
              // We need to handle the next ncaptures arguments.
              if i + r.ncaptures - 1 > k {
                error = qio_format_error_too_few_args();
                if _format_debug then stdout.writeln("TODO AXH");
              }
              for z in 0..#r.ncaptures {
                if i+z <= argType.size {
                  argType(i+z+1) = QIO_CONV_SET_CAPTURE;
                }
              }
            } when QIO_CONV_ARG_TYPE_REPR {
              error = _read_one_internal(_channel_internal, iokind.dynamic, args(i));
            } when QIO_CONV_SET_CAPTURE {
              if r == nil {
                error = qio_format_error_bad_regexp();
                if _format_debug then stdout.writeln("TODO AXI");
              } else {
                _match_regexp_if_needed(cur, len, error, style, r);
                // Set args(i) to the catpure at capturei.
                if r.capturei >= r.ncaptures {
                  error = qio_format_error_bad_regexp();
                  if _format_debug then stdout.writeln("TODO AXJ");
                } else {
                  // We have a string in captures[capturei] and
                  // we need to set args(i) to that.
                  args(i) = r.capArr[r.capturei]:args(i).type;
                  r.capturei += 1;
                }
              }
            } otherwise {
              halt("Internal error in readf/writef");
            }
          }
        }
      }

      if ! error {
        if cur < len {
          var dummy:c_int;
          _format_reader(fmt, cur, len, error,
                         conv, gotConv, style, r,
                         true);
        }

        if cur < len {
          // Mismatched number of arguments!
          error = qio_format_error_too_few_args();
          if _format_debug then stdout.writeln("TODO AXL");
        }
      }

      if r != nil {
        delete r;
      }

      if ! error {
        // commit.
        qio_channel_commit_unlocked(_channel_internal);
      } else {
        // revert
        qio_channel_revert_unlocked(_channel_internal);
      }
    }
    this._set_style(save_style);
    this.unlock();
  }
  return !error;
}

proc channel.readf(fmt:string, out error:syserr):bool {
  if writing then compilerError("readf on write-only channel");
  error = ENOERR;
  on this.home {
    this.lock();
    var save_style = this._style();
    var cur:size_t = 0;
    var len:size_t = fmt.length:size_t;
    var conv:qio_conv_t;
    var gotConv:bool;
    var style:iostyle;
    var end:size_t;
    var dummy:c_int;

    var r:_channel_regexp_info = nil;

    error = qio_channel_mark(false, _channel_internal);
    if !error {
      if _format_debug then stdout.writeln("TODO BBBB");
      _format_reader(fmt, cur, len, error,
                     conv, gotConv, style, r,
                     true);
      if gotConv {
        error = qio_format_error_too_few_args();
        if _format_debug then stdout.writeln("TODO ABZOO");
      }
    }
    if !error {
      if cur < len {
        error = qio_format_error_too_few_args();
        if _format_debug then stdout.writeln("TODO AXM");
      }
    }
    if ! error {
      // commit.
      qio_channel_commit_unlocked(_channel_internal);
    } else {
      // revert
      qio_channel_revert_unlocked(_channel_internal);
    }

    this._set_style(save_style);
    this.unlock();
  }
  return !error;
}



proc channel.writef(fmt:string, args ...?k) {
  var e:syserr = ENOERR;
  this.writef(fmt, (...args), error=e);
  if !e then return true;
  else {
    this._ch_ioerror(e, "in channel.writef(fmt:string, ...)");
    return false;
  }
}
proc channel.writef(fmt:string) {
  var e:syserr = ENOERR;
  this.writef(fmt, error=e);
  if !e then return true;
  else {
    this._ch_ioerror(e, "in channel.writef(fmt:string, ...)");
    return false;
  }
}


proc channel.readf(fmt:string, ref args ...?k) {
  var e:syserr = ENOERR;
  this.readf(fmt, (...args), error=e);
  if !e then return true;
  else if e == EEOF then return false;
  else if e == EFORMAT then return false;
  else {
    this._ch_ioerror(e, "in channel.readf(fmt:string, ...)");
    return false;
  }
}

proc channel.readf(fmt:string) {
  var e:syserr = ENOERR;
  this.readf(fmt, error=e);
  if !e then return true;
  else if e == EEOF then return false;
  else if e == EFORMAT then return false;
  else {
    this._ch_ioerror(e, "in channel.readf(fmt:string, ...)");
    return false;
  }
}

proc writef(fmt:string, args ...?k):bool {
  return stdout.writef(fmt, (...args));
}
proc writef(fmt:string):bool {
  return stdout.writef(fmt);
}
proc readf(fmt:string, ref args ...?k):bool {
  return stdin.readf(fmt, (...args));
}
proc readf(fmt:string):bool {
  return stdin.readf(fmt);
}


use Regexp;
extern proc qio_regexp_channel_match(ref re:qio_regexp_t, threadsafe:c_int, ch:qio_channel_ptr_t, maxlen:int(64), anchor:c_int, can_discard:bool, keep_unmatched:bool, keep_whole_pattern:bool, submatch:_ddata(qio_regexp_string_piece_t), nsubmatch:int(64)):err_t;

proc channel._extractMatch(m:reMatch, ref arg:reMatch, ref error:syserr) {
  // If the argument is a match record, just return it.
  arg = m;
}
 
proc channel._extractMatch(m:reMatch, ref arg:string, ref error:syserr) {
  var cur:int(64);
  var target = m.offset;
  var len = m.length;

  // If there was no match, return the default value of the type
  if !m.matched {
    arg = "";
  }

  // Read into a string the appropriate region of the file.
  if !error {
    qio_channel_revert_unlocked(_channel_internal);
    error = qio_channel_mark(false, _channel_internal);
    cur = qio_channel_offset_unlocked(_channel_internal);
  }

  if ! error {
    // There was a match, so we have to read the
    // strings for the capture groups.
    error = qio_channel_advance(false, _channel_internal, target - cur);
  }

  var s:string;
  if ! error {
    var gotlen:ssize_t;
    error = qio_channel_read_string(false, iokind.native, stringStyleExactLen(len), _channel_internal, s, gotlen, len);
  }
 
  if ! error {
    arg = s;
  } else {
    arg = "";
  }
}
 
proc channel._extractMatch(m:reMatch, ref arg:?t, ref error:syserr) where t != reMatch && t != string {
  // If there was no match, return the default value of the type
  if !m.matched {
    var empty:arg.type;
    arg = empty;
  }

  // Read into a string the appropriate region of the file.
  var s:string;
  _extractMatch(m, s, error);
 
  if ! error {
    arg = s:arg.type;
  } else {
    var empty:arg.type;
    arg = empty;
  }
}


/** Sets arg to the string of a match.
    If arg is not a string, the match will be coerced to a arg.type.

    Assumes that the channel has been marked before where
    the captures are being returned. Will change the channel
    position to just after the match. Will not do anything
    if error is set.
 */
proc channel.extractMatch(m:reMatch, ref arg, ref error:syserr) {
  on this.home {
    this.lock();
    _extractMatch(m, arg, error);
    this.unlock();
  }
}
proc channel.extractMatch(m:reMatch, ref arg) {
  on this.home {
    this.lock();
    var err:syserr = ENOERR;
    _extractMatch(m, arg, err);
    if err {
      this._ch_ioerror(err, "in channel.extractMatch(m:reMatch, ref " +
                             typeToString(arg.type) + ")");
    }
    this.unlock();
  }
}

// Assumes that the channel has been marked where the search began
// (or at least before the capture groups if discarding)
proc channel._ch_handle_captures(matches:_ddata(qio_regexp_string_piece_t),
                                 nmatches:int,
                                 ref captures, ref error:syserr) {
  assert(nmatches >= captures.size);
  for param i in 1..captures.size {
    var m = _to_reMatch(matches[i]);
    _extractMatch(m, captures[i], error);
  }
}


/** Search for an offset in the channel matching the
    passed regular expression, possibly pulling out capture groups.
    If there is a match, leaves the channel position at the
    match. If there is no match, the channel position will be
    advanced to the end of the channel (or end of the file).
 */
proc channel.search(re:regexp, ref error:syserr):reMatch
{
  var m:reMatch;
  on this.home {
    this.lock();
    var nm = 1;
    var matches = _ddata_allocate(qio_regexp_string_piece_t, nm);
    error = qio_channel_mark(false, _channel_internal);
    if !error {
      error = qio_regexp_channel_match(re._regexp,
                                       false, _channel_internal, max(int(64)),
                                       QIO_REGEXP_ANCHOR_UNANCHORED,
                                       /* can_discard */ true,
                                       /* keep_unmatched */ false,
                                       /* keep_whole_pattern */ true,
                                       matches, nm);
    }
    // Don't report "didn't match" errors
    if error == EFORMAT || error == EEOF then error = ENOERR;
    if !error {
      m = _to_reMatch(matches[0]);
      if m.matched {
        // Advance to the match.
        qio_channel_revert_unlocked(_channel_internal);
        var cur = qio_channel_offset_unlocked(_channel_internal);
        var target = m.offset;
        error = qio_channel_advance(false, _channel_internal, target - cur);
      } else {
        // If we didn't match... leave the channel position at EOF
        qio_channel_commit_unlocked(_channel_internal);
      }
    }
    _ddata_free(matches);
    this.unlock();
  }
  return m;
}

proc channel.search(re:regexp):reMatch
{
  var e:syserr = ENOERR;
  var ret = this.search(re, error=e);
  if e then this._ch_ioerror(e, "in channel.search");
  return ret;
}

/** Like channel.search but assigning capture groups to arguments.
 */
proc channel.search(re:regexp, ref captures ...?k, ref error:syserr):reMatch
{
  var m:reMatch;
  on this.home {
    this.lock();
    var nm = captures.size + 1;
    var matches = _ddata_allocate(qio_regexp_string_piece_t, nm);
    error = qio_channel_mark(false, _channel_internal);
    if ! error {
      error = qio_regexp_channel_match(re._regexp,
                                       false, _channel_internal, max(int(64)),
                                       QIO_REGEXP_ANCHOR_UNANCHORED,
                                       /* can_discard */ true,
                                       /* keep_unmatched */ false,
                                       /* keep_whole_pattern */ true,
                                       matches, nm);
    }
    // Don't report "didn't match" errors
    if error == EFORMAT || error == EEOF then error = ENOERR;
    if !error {
      m = _to_reMatch(matches[0]);
      if m.matched {
        // Extract the capture groups.
        _ch_handle_captures(matches, nm, captures, error);

        // Advance to the match.
        qio_channel_revert_unlocked(_channel_internal);
        var cur = qio_channel_offset_unlocked(_channel_internal);
        var target = m.offset;
        error = qio_channel_advance(false, _channel_internal, target - cur);
      } else {
        // If we didn't match... leave the channel position at EOF
        qio_channel_commit_unlocked(_channel_internal);
      }
    }
    _ddata_free(matches);
    this.unlock();
  }
  return m;
}
proc channel.search(re:regexp, ref captures ...?k):reMatch
{
  var e:syserr = ENOERR;
  var ret = this.search(re, (...captures), error=e);
  if e then this._ch_ioerror(e, "in channel.search");
  return ret;
}


/* Match, starting at the current position in the channel,
   against a regexp, possibly pulling out capture groups.
   If there was a match, leaves the channel position at
   the match. If there was no match, leaves the channel
   position where it was at the start of this call.
 */
proc channel.match(re:regexp, ref error:syserr):reMatch
{
  var m:reMatch;
  on this.home {
    this.lock();
    var nm = 1;
    var matches = _ddata_allocate(qio_regexp_string_piece_t, nm);
    error = qio_channel_mark(false, _channel_internal);
    if ! error {
      error = qio_regexp_channel_match(re._regexp,
                                       false, _channel_internal, max(int(64)),
                                       QIO_REGEXP_ANCHOR_START,
                                       /* can_discard */ true,
                                       /* keep_unmatched */ true,
                                       /* keep_whole_pattern */ true,
                                       matches, nm);
    }
    // Don't report "didn't match" errors
    if error == EFORMAT || error == EEOF then error = ENOERR;
    if !error {
      m = _to_reMatch(matches[0]);
      if m.matched {
        // Advance to the match.
        qio_channel_revert_unlocked(_channel_internal);
        var cur = qio_channel_offset_unlocked(_channel_internal);
        var target = m.offset;
        error = qio_channel_advance(false, _channel_internal, target - cur);
      } else {
        // If we didn't match... leave the channel position at start
        qio_channel_revert_unlocked(_channel_internal);
      }
    }
    _ddata_free(matches);
    this.unlock();
  }
  return m;
}
proc channel.match(re:regexp):reMatch
{
  var e:syserr = ENOERR;
  var ret = this.match(re, error=e);
  if e then this._ch_ioerror(e, "in channel.match");
  return ret;
}


proc channel.match(re:regexp, ref captures ...?k, ref error:syserr):reMatch
{
  var m:reMatch;
  on this.home {
    this.lock();
    var nm = 1 + captures.size;
    var matches = _ddata_allocate(qio_regexp_string_piece_t, nm);
    error = qio_channel_mark(false, _channel_internal);
    if !error {
      error = qio_regexp_channel_match(re._regexp,
                               false, _channel_internal, max(int(64)),
                               QIO_REGEXP_ANCHOR_START,
                               /* can_discard */ true,
                               /* keep_unmatched */ true,
                               /* keep_whole_pattern */ true,
                               matches, nm);
    }
    // Don't report "didn't match" errors
    if error == EFORMAT || error == EEOF then error = ENOERR;
    if !error {
      m = _to_reMatch(matches[0]);
      if m.matched {
        // Extract the capture groups.
        _ch_handle_captures(matches, nm, captures, error);

        // Advance to the match.
        qio_channel_revert_unlocked(_channel_internal);
        var cur = qio_channel_offset_unlocked(_channel_internal);
        var target = m.offset;
        error = qio_channel_advance(false, _channel_internal, target - cur);
      } else {
        // If we didn't match... leave the channel position at start
        qio_channel_revert_unlocked(_channel_internal);
      }
    }
    _ddata_free(matches);
    this.unlock();
  }
  return m;
}
proc channel.match(re:regexp, ref captures ...?k):reMatch
{
  var e:syserr = ENOERR;
  var ret = this.match(re, (...captures), error=e);
  if e then this._ch_ioerror(e, "in channel.match");
  return ret;
}



/* Enumerates matches in the string as well as capture groups.
   Returns tuples of reMatch objects, the 1st is always
    the match for the whole pattern.
   At the time each match is returned, the channel position is
    at the start of that match. Note though that you would have
    to advance to get to the position of a capture group.
   After returning each match, advances to just after that
    match and looks for another match. Thus, it will not return
    overlapping matches.
   In the end, leaves the channel position at the end of the
    last reported match (if we ran out of maxmatches)
    or at the end of the channel (if we no longer matched)
   Holds the channel lock for the duration of the search.
 */
iter channel.matches(re:regexp, param captures=0, maxmatches:int = max(int))
{
  var m:reMatch;
  var go = true;
  var i = 0;
  var error:syserr = ENOERR;
  param nret = captures+1;
  var ret:nret*reMatch;

  lock();
  on this.home do error = _mark();
  if error then this._ch_ioerror(error, "in channel.matches mark");

  while go && i < maxmatches {
    on this.home {
      var nm = 1 + captures;
      var matches = _ddata_allocate(qio_regexp_string_piece_t, nm);
      if ! error {
        error = qio_regexp_channel_match(re._regexp,
                                 false, _channel_internal, max(int(64)),
                                 QIO_REGEXP_ANCHOR_UNANCHORED,
                                 /* can_discard */ true,
                                 /* keep_unmatched */ false,
                                 /* keep_whole_pattern */ true,
                                 matches, nm);
      }
      if !error {
        m = _to_reMatch(matches[0]);
        if m.matched {
          for param i in 1..nret {
            m = _to_reMatch(matches[i-1]);
            _extractMatch(m, ret[i], error);
          }
          // Advance to the start of the match.
          qio_channel_revert_unlocked(_channel_internal);
          error = qio_channel_mark(false, _channel_internal);
          if !error {
            var cur = qio_channel_offset_unlocked(_channel_internal);
            var target = m.offset;
            error = qio_channel_advance(false, _channel_internal, target - cur);
          }
        } else {
          // Stay at the end of the searched region.
        }
      }
      _ddata_free(matches);
      if error then go = false;
    }
    if ! error then yield ret;
    i += 1;
  }
  _commit();
  unlock();
  // Don't report didn't find or end-of-file errors.
  if error == EFORMAT || error == EEOF then error = ENOERR;
  if error then this._ch_ioerror(error, "in channel.matches");
}
