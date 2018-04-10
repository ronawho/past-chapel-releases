.. default-domain:: chpl

.. module:: String
   :synopsis: The following documentation shows functions and methods used to

Strings
=======
The following documentation shows functions and methods used to
manipulate and process Chapel strings.

Besides the functions below, some other modules proved routines that are
useful for working with strings. The :mod:`IO` module provides
:proc:`IO.string.format` which creates a string that is the result of
formatting. It also includes functions for reading and writing strings.
The :mod:`Regexp` module also provides some routines for searching
within strings.

.. warning::

  Casts from :record:`string` to the following types will throw an error
  if they are invalid:

    - ``int``
    - ``uint``
    - ``real``
    - ``imag``
    - ``complex``
    - ``enum``

  To learn more about handling these errors, see the
  :ref:`Error Handling technical note <readme-errorHandling>`.

.. note::

  While :record:`string` is intended to be a Unicode string, there is much
  left to do. As of Chapel 1.17, only ASCII strings can be expected to work
  correctly with all functions.

  Future work involves support for both ASCII and unicode strings, and
  allowing users to specify the encoding for individual strings.


.. record:: string

   .. method:: proc string(s: string, owned: bool = true)

      
      Construct a new string from ``s``. If ``owned`` is set to ``true`` then
      ``s`` will be fully copied into the new instance. If it is ``false`` a
      shallow copy will be made such that any in-place modifications to the new
      string may appear in ``s``. It is the responsibility of the user to
      ensure that the underlying buffer is not freed while being used as part
      of a shallow copy.
      

   .. method:: proc string(cs: c_string, length: int = cs.length, owned: bool = true, needToCopy: bool = true)

      
      Construct a new string from the `c_string` `cs`. If `owned` is set to
      true, the backing buffer will be freed when the new record is destroyed.
      If `needToCopy` is set to true, the `c_string` will be copied into the
      record, otherwise it will be used directly. It is the responsibility of
      the user to ensure that the underlying buffer is not freed if the
      `c_string` is not copied in.
      

   .. method:: proc string(buff: bufferType, length: int, size: int, owned: bool = true, needToCopy: bool = true)

      
      Construct a new string from `buff` ( `c_ptr(uint(8))` ). `size` indicates
      the total size of the buffer available, while `len` indicates the current
      length of the string in the buffer (the common case would be `size-1` for
      a C-style string). If `owned` is set to true, the backing buffer will be
      freed when the new record is destroyed. If `needToCopy` is set to true,
      the `c_string` will be copied into the record, otherwise it will be used
      directly. It is the responsibility of the user to ensure that the
      underlying buffer is not freed if the `c_string` is not copied in.
      

   .. method:: proc length

      
      :returns: The number of characters in the string.
      

   .. method:: proc size

      
      :returns: The number of characters in the string.
      

   .. method:: proc localize(): string

      
      Gets a version of the :record:`string` that is on the currently
      executing locale.
      
      :returns: A shallow copy if the :record:`string` is already on the
                current locale, otherwise a deep copy is performed.
      

   .. method:: proc c_str(): c_string

      
      Get a `c_string` from a :record:`string`.
      
      .. warning::
      
          This can only be called safely on a :record:`string` whose home is
          the current locale.  This property can be enforced by calling
          :proc:`string.localize()` before :proc:`~string.c_str()`. If the
          string is remote, the program will halt.
      
      For example:
      
      .. code-block:: chapel
      
          var my_string = "Hello!";
          on different_locale {
            printf("%s", my_string.localize().c_str());
          }
      
      :returns:
          A `c_string` that points to the underlying buffer used by this
          :record:`string`. The returned `c_string` is only valid when used
          on the same locale as the string.
      

   .. itermethod:: iter these(): string

      
      Iterates over the string character by character.
      
      For example:
      
      .. code-block:: chapel
      
        var str = "abcd";
        for c in str {
          writeln(c);
        }
      
      Output::
      
        a
        b
        c
        d
      

   .. method:: proc this(i: int): string

      
      Index into a string
      
      :returns: A string with the character at the specified index from
                `1..string.length`
      

   .. method:: proc this(r: range(?)): string

      
      Slice a string. Halts if r is not completely inside the range
      `1..string.length`.
      
      :arg r: range of the indices the new string should be made from
      
      :returns: a new string that is a substring within `1..string.length`. If
                the length of `r` is zero, an empty string is returned.
      

   .. method:: proc isEmptyString(): bool

      
      :returns: * `true`  -- when the string is empty
                * `false` -- otherwise
      

   .. method:: proc startsWith(needles: string ...): bool

      
      :arg needles: A varargs list of strings to match against.
      
      :returns: * `true`  -- when the string begins with one or more of the `needles`
                * `false` -- otherwise
      

   .. method:: proc endsWith(needles: string ...): bool

      
      :arg needles: A varargs list of strings to match against.
      
      :returns: * `true`  -- when the string ends with one or more of the `needles`
                * `false` -- otherwise
      

   .. method:: proc find(needle: string, region: range(?) = 1..): int

      
      :arg needle: the string to search for
      :arg region: an optional range defining the substring to search within,
                   default is the whole string. Halts if the range is not
                   within `1..string.length`
      
      :returns: the index of the first occurrence of `needle` within a
                string, or 0 if the `needle` is not in the string.
      

   .. method:: proc rfind(needle: string, region: range(?) = 1..): int

      
      :arg needle: the string to search for
      :arg region: an optional range defining the substring to search within,
                   default is the whole string. Halts if the range is not
                   within `1..string.length`
      
      :returns: the index of the first occurrence from the right of `needle`
                within a string, or 0 if the `needle` is not in the string.
      

   .. method:: proc count(needle: string, region: range(?) = 1..): int

      
      :arg needle: the string to search for
      :arg region: an optional range defining the substring to search within,
                   default is the whole string. Halts if the range is not
                   within `1..string.length`
      
      :returns: the number of times `needle` occurs in the string
      

   .. method:: proc replace(needle: string, replacement: string, count: int = -1): string

      
      :arg needle: the string to search for
      :arg replacement: the string to replace `needle` with
      :arg count: an optional integer specifying the number of replacements to
                  make, values less than zero will replace all occurrences
      
      :returns: a copy of the string where `replacement` replaces `needle` up
                to `count` times
      

   .. itermethod:: iter split(sep: string, maxsplit: int = -1, ignoreEmpty: bool = false)

      
      Splits the string on `sep` yielding the substring between each
      occurrence, up to `maxsplit` times.
      
      :arg sep: The delimiter used to break the string into chunks.
      :arg maxsplit: The number of times to split the string, negative values
                     indicate no limit.
      :arg ignoreEmpty: * When `true`  -- Empty strings will not be yielded,
                                          and will not count towards `maxsplit`
                        * When `false` -- Empty strings will be yielded when
                                          `sep` occurs multiple times in a row.
      

   .. itermethod:: iter split(maxsplit: int = -1)

      
      Works as above, but uses runs of whitespace as the delimiter.
      
      :arg maxsplit: The number of times to split the string, negative values
                     indicate no limit.
      

   .. method:: proc join(const ref S: string ...): string

      
      Returns a new string, which is the concatenation of all of the strings
      passed in with the receiving string inserted between them.
      
      .. code-block:: chapel
      
          var x = "|".join("a","10","d");
          writeln(x); // prints: "a|10|d"
      

   .. method:: proc join(const ref S): string

      
      Same as the varargs version, but with a homogeneous tuple of strings.
      
      .. code-block:: chapel
      
          var x = "|".join("a","10","d");
          writeln(x); // prints: "a|10|d"
      

   .. method:: proc join(const ref S: [] string): string

      
      Same as the varargs version, but with all the strings in an array.
      
      .. code-block:: chapel
      
          var x = "|".join(["a","10","d"]);
          writeln(x); // prints: "a|10|d"
      

   .. method:: proc _join(const ref S): string

   .. method:: proc strip(chars: string = " \t\r\n", leading = true, trailing = true): string

      
      :arg chars: A string containing each character to remove.
                  Defaults to `" \\t\\r\\n"`.
      :arg leading: Indicates if leading occurrences should be removed.
                    Defaults to `true`.
      :arg trailing: Indicates if trailing occurrences should be removed.
                     Defaults to `true`.
      
      :returns: A new string with `leading` and/or `trailing` occurrences of
                characters in `chars` removed as appropriate.
      

   .. method:: proc partition(sep: string): 3*(string)

      
      Splits the string on `sep` into a `3*string` consisting of the section
      before `sep`, `sep`, and the section after `sep`. If `sep` is not found,
      the tuple will contain the whole string, and then two empty strings.
      

   .. method:: proc isUpper(): bool

      
      Checks if all the characters in the string are either uppercase (A-Z) or
      uncased (not a letter).
      
       :returns: * `true`  -- if the string contains at least one uppercase
                              character and no lowercase characters, ignoring
                              uncased characters.
                 * `false` -- otherwise
      

   .. method:: proc isLower(): bool

      
      Checks if all the characters in the string are either lowercase (a-z) or
      uncased (not a letter).
      
       :returns: * `true`  -- when there are no uppercase characters in the string.
                 * `false` -- otherwise
      

   .. method:: proc isSpace(): bool

      
      Checks if all the characters in the string are whitespace (' ', '\t',
      '\n', '\v', '\f', '\r').
      
       :returns: * `true`  -- when all the characters are whitespace.
                 * `false` -- otherwise
      

   .. method:: proc isAlpha(): bool

      
      Checks if all the characters in the string are alphabetic (a-zA-Z).
      
       :returns: * `true`  -- when the characters are alphabetic.
                 * `false` -- otherwise
      

   .. method:: proc isDigit(): bool

      
      Checks if all the characters in the string are digits (0-9).
      
       :returns: * `true`  -- when the characters are digits.
                 * `false` -- otherwise
      

   .. method:: proc isAlnum(): bool

      
      Checks if all the characters in the string are alphanumeric (a-zA-Z0-9).
      
       :returns: * `true`  -- when the characters are alphanumeric.
                 * `false` -- otherwise
      

   .. method:: proc isPrintable(): bool

      
      Checks if all the characters in the string are printable. Characters are
      defined as being printable if they are within the range of `0x20 - 0x7e`
      including the bounds.
      
       :returns: * `true`  -- when the characters are printable.
                 * `false` -- otherwise
      

   .. method:: proc isTitle(): bool

      
      Checks if all uppercase characters are preceded by uncased characters,
      and if all lowercase characters are preceded by cased characters.
      
      :returns: * `true`  -- when the condition described above is met.
                * `false` -- otherwise
      

   .. method:: proc toLower(): string

      
      :returns: A new string with all uppercase characters replaced with their
                lowercase counterpart.
      

   .. method:: proc toUpper(): string

      
      :returns: A new string with all lowercase characters replaced with their
                uppercase counterpart.
      

   .. method:: proc toTitle(): string

      
      :returns: A new string with all cased characters following an uncased
                character converted to uppercase, and all cased characters
                following another cased character converted to lowercase.
      

.. function:: proc =(ref lhs: string, rhs: string)

   
   Copies the string `rhs` into the string `lhs`.
   

.. function:: proc =(ref lhs: string, rhs_c: c_string)

   
   Copies the c_string `rhs_c` into the string `lhs`.
   
   Halts if `lhs` is a remote string.
   

.. function:: proc +(s0: string, s1: string)

   
   :returns: A new string which is the result of concatenating `s0` and `s1`
   

.. function:: proc *(s: string, n: integral)

   
   :returns: A new string which is the result of repeating `s` `n` times.
             If `n` is less than or equal to 0, an empty string is returned.
   
   For example:
   
   .. code-block:: chapel
   
      writeln("Hello! " * 3);
   
   Results in::
   
     Hello! Hello! Hello!
   

.. function:: proc +(s: string, x: numeric)

   
   The following concatenation functions return a new string which is the
   result of casting the non-string argument to a string, and concatenating
   that result with `s`.
   

.. function:: proc +(x: numeric, s: string)

.. function:: proc +(s: string, x: enumerated)

.. function:: proc +(x: enumerated, s: string)

.. function:: proc +(s: string, x: bool)

.. function:: proc +(x: bool, s: string)

.. function:: proc +=(ref lhs: string, const ref rhs: string): void

   
   Appends the string `rhs` to the string `lhs`.
   

.. function:: proc ascii(a: string): uint(8)

   
   :returns: The byte value of the first character in `a` as an integer.
   

.. function:: proc asciiToString(i: uint(8))

   
   :returns: A string with the single character with the ASCII value `i`.
   

