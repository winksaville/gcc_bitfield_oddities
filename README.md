GCC has at least two bitfield oddities.

Bit fields > 32 have their with encoded in there type and this causes
two problems.

- You can't use the C11 _Generic syntax to create an association.

- You can't print bit fields without casts to supress the warnings
when using -Wall you get warnings.

Both appear to be caused by the encoded type information. With clang
there are not those problems and it doesn't appear to encode the length.
In addition left shifts don't get truncated at the bit width boundrary
as they do with gcc.
