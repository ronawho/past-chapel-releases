/**************************************************************************
  Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
**************************************************************************/


#include "chplrt.h"

#include "chplfp.h"
#include "chpl-mem.h"
#include "chplcgfns.h"
#include "chpl-comm.h"
#include "chpl-comm-compiler-macros.h"
#include "error.h"

#include <inttypes.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define NANSTRING "nan"
#define NEGINFSTRING "-inf"
#define POSINFSTRING "inf"

const char* _default_format_write_complex64 = "%g + %gi";
const char* _default_format_write_complex128 = "%g + %gi";

char* chpl_glom_strings(int numstrings, ...) {
  va_list ap;
  int i, len;
  char* str;

  va_start(ap, numstrings);
  len = 0;
  for (i=0; i<numstrings; i++)
    len += strlen(va_arg(ap, char*));
  va_end(ap);

  str = (char*)chpl_mem_allocMany(len+1, sizeof(char),
                                  CHPL_RT_MD_GLOM_STRINGS_DATA, 0, 0);

  va_start(ap, numstrings);
  str[0] = '\0';
  for (i=0; i<numstrings; i++)
    strcat(str, va_arg(ap, char*));
  va_end(ap);

  return str;
}


chpl_string chpl_format(chpl_string format, ...) {
  va_list ap;
  char z[128];

  va_start(ap, format);
  if (!vsnprintf(z, 127, format, ap))
    chpl_error("overflow encountered in format", 0, 0);
  return string_copy(z, 0, 0);
}


#ifndef LAUNCHER
// TODO: This declaration should actually come from chplcgfns.h
// but some factoring of the runtime includes is required to make this work.
// See the comment ca. chplcgfns.h:21 for more info.
typedef struct __chpl_localeID_t {
  c_nodeid_t node;
  c_subloc_t subloc;
} chpl_localeID_t;

struct chpl_chpl____wide_chpl_string_s {
  chpl_localeID_t locale;
  chpl_string addr;
  int64_t size;
};
typedef struct chpl_chpl____wide_chpl_string_s chpl____wide_chpl_string;

chpl_string
chpl_wide_string_copy(chpl____wide_chpl_string* x, int32_t lineno, chpl_string filename) {
  if (x->locale.node == chpl_nodeID)
    return string_copy(x->addr, lineno, filename);
  else {
    chpl_string s;
    chpl_comm_wide_get_string(&s, x,
                              -CHPL_TYPE_chpl_string /* this is unfortunate */,
                              lineno, filename);
    return s;
  }
}

// un-macro'd CHPL_WIDEN_STRING
void
chpl_string_widen(chpl____wide_chpl_string* x, chpl_string from)
{
  size_t len = strlen(from) + 1;
  x->locale.node = chpl_nodeID;
  x->locale.subloc = chpl_task_getSubLoc();
  x->addr = chpl_mem_allocMany(len, sizeof(char),
                               CHPL_RT_MD_SET_WIDE_STRING, 0, 0);
  strncpy((char*)x->addr, from, len);
  x->size = len;
}

// un-macro'd CHPL_COMM_WIDE_GET_STRING
void
chpl_comm_wide_get_string(chpl_string* local, struct chpl_chpl____wide_chpl_string_s* x, int32_t tid, int32_t lineno, chpl_string filename)
{
  char* chpl_macro_tmp =
      chpl_mem_allocMany(x->size, sizeof(char),
                         CHPL_RT_MD_GET_WIDE_STRING, -1, "<internal>");
    if (chpl_nodeID == x->locale.node)
      memcpy(chpl_macro_tmp, x->addr, x->size);
    else
      chpl_comm_get((void*) &(*chpl_macro_tmp), x->locale.node,
                    (void*)(x->addr),
                    sizeof(char), tid, x->size, lineno, filename);
    *local = chpl_macro_tmp;
}


#endif


chpl_string
string_copy(chpl_string x, int32_t lineno, chpl_string filename)
{
  char *z;

  // hilde sez: if the input string is null, just return null.
  if (x == NULL)
    return NULL;

  z = (char*)chpl_mem_allocMany(strlen(x)+1, sizeof(char),
                                      CHPL_RT_MD_STRING_COPY_DATA,
                                      lineno, filename);
  return strcpy(z, x);
}


chpl_string
string_concat(chpl_string x, chpl_string y, int32_t lineno, chpl_string filename) {
  char *z = (char*)chpl_mem_allocMany(strlen(x)+strlen(y)+1, sizeof(char),
                                      CHPL_RT_MD_STRING_CONCAT_DATA,
                                      lineno, filename);
  z[0] = '\0';
  strcat(z, x);
  strcat(z, y);
  return z;
}


chpl_string
string_strided_select(chpl_string x, int low, int high, int stride, int32_t lineno, chpl_string filename) {
  int64_t length = string_length(x);
  char* result = NULL;
  char* dst = NULL;
  chpl_string src = stride > 0 ? x + low - 1 : x + high - 1;
  int size = high - low >= 0 ? high - low : 0;
  if (low < 1 || low > length || high > length) {
    chpl_error("string index out of bounds", lineno, filename);
  }
  result = chpl_mem_allocMany(size + 2, sizeof(char),
                              CHPL_RT_MD_STRING_STRIDED_SELECT_DATA,
                              lineno, filename);
  dst = result;
  if (stride > 0) {
    while (src - x <= high - 1) {
      *dst++ = *src;
      src += stride;
    }
  } else {
    while (src - x >= low - 1) {
      *dst++ = *src;
      src += stride;
    }
  }
  *dst = '\0';
  return chpl_glom_strings(1, result);
}

chpl_string
string_select(chpl_string x, int low, int high, int32_t lineno, chpl_string filename) {
  return string_strided_select(x, low, high, 1, lineno, filename);
}

chpl_string
string_index(chpl_string x, int i, int32_t lineno, chpl_string filename) {
  char buffer[2];
  if (i-1 < 0 || i-1 >= string_length(x))
    chpl_error("string index out of bounds", lineno, filename);
  sprintf(buffer, "%c", x[i-1]);
  return chpl_glom_strings(1, buffer);
}


chpl_bool
string_contains(chpl_string x, chpl_string y) {
  if (strstr(x, y))
    return true;
  else
    return false;
}


int32_t chpl_string_compare(chpl_string x, chpl_string y) {
  return (int32_t)strcmp(x, y);
}


int64_t
string_length(chpl_string x) {
  return strlen(x);
}


int64_t real2int( _real64 f) {
  // need to use a union here rather than a pointer cast to avoid gcc
  // warnings when compiling -O3
  union {
    _real64 r;
    uint64_t u;
  } converter;

  converter.r = f;
  return converter.u;
}


int64_t
object2int( _chpl_object o) {
  return (intptr_t) o;
}

const char* chpl_get_argument_i(chpl_main_argument* args, int32_t i)
{
  if( i < 0 ) return NULL;
  if( i > args->argc ) return NULL;
  return args->argv[i];
}
