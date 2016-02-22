/*
 * Copyright 2016 Wink Saville
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdio.h>

struct big_bit_fields {
  _Bool b1:1;
  int b2:2;
  long unsigned int b33:33;
} __attribute__((__packed__));

_Static_assert(sizeof(struct big_bit_fields) == 5,
    L"big_bit_fields is not 5 bytes");


#define type_to_str(__x) _Generic((0)?(__x):(__x), \
  _Bool : "_Bool", \
  char : "char", \
  signed char : "unsigned char", \
  unsigned char : "unsigned char", \
  short int : "short int", \
  unsigned short int: "unsigned short int", \
  int : "int", \
  unsigned int : "unsigned int", \
  long int : "long int", \
  long unsigned int : "long unsigned int", \
  long long int : "long long int", \
  long long unsigned int : "long long unsigned int", \
  default : "unknown type")

int main(void) {
  struct big_bit_fields bbf = { .b1 = 1, .b2 = 3, .b33 = 0x1FFFFFFFF };

  printf("bbf.b1=0x%x type=%s\n", bbf.b1, type_to_str(bbf.b1));
  printf("bbf.b2=0x%x type=%s\n", bbf.b2, type_to_str(bbf.b2));
  printf("bbf.b33=0x%lx type=%s\n", bbf.b33, type_to_str(bbf.b33));
  printf("       <<1 =0x%016lx\n", bbf.b33 << 1);
  printf("  (ull)<<1 =0x%016lx\n", (long unsigned int)bbf.b33 << 1);

  return 0;
}
