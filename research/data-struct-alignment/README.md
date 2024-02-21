## macos
```txt
__APPLE__: 1
__aarch64__: 1
__cplusplus: 202002
__VERSION__: Apple LLVM 15.0.0 (clang-1500.1.0.2.5)


Fixed width integer types: 
TYPE(SIZE): ALIGNMENT
--------------------
int8_t(1): 1
int16_t(2): 2
int32_t(4): 4
int64_t(8): 8
int_fast8_t(1): 1
int_fast16_t(2): 2
int_fast32_t(4): 4
int_fast64_t(8): 8
int_least8_t(1): 1
int_least16_t(2): 2
int_least32_t(4): 4
int_least64_t(8): 8
uint8_t(1): 1
uint16_t(2): 2
uint32_t(4): 4
uint64_t(8): 8
uint_fast8_t(1): 1
uint_fast16_t(2): 2
uint_fast32_t(4): 4
uint_fast64_t(8): 8
uint_least8_t(1): 1
uint_least16_t(2): 2
uint_least32_t(4): 4
uint_least64_t(8): 8
uintmax_t(8): 8
uintptr_t(8): 8


Other types: 
TYPE(SIZE): ALIGNMENT
--------------------
size_t(8): 8
bool(1): 1
int(4): 4
short(2): 2
long(8): 8
long long(8): 8
float(4): 4
double(8): 8
long double(8): 8
char(1): 1
wchar_t(4): 4
ptrdiff_t(8): 8
nullptr_t(8): 8
max_align_t(8): 8


Example struct:
TYPE(SIZE, ALIGNMENT)
--------------------
          TYPE_0(1, 1)

          TYPE_A(48, 8)
          +-+-+-+-+-+-+-+-+
000000(D) |* * * *|*|*|     int(4, 4) char(1, 1) char(1, 1) 
          +-+-+-+-+-+-+-+-+
000008(D) |* * * * * * * *| double(8, 8) 
          +-+-+-+-+-+-+-+-+
000016(D) |*| |* *|         char(1, 1) short(2, 2) 
          +-+-+-+-+-+-+-+-+
000024(D) |* * * * * * * *  std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>(24, 8) 
          +-+-+-+-+-+-+-+-+
000032(D)  * * * * * * * *  
          +-+-+-+-+-+-+-+-+
000040(D)  * * * * * * * *| 
          +-+-+-+-+-+-+-+-+

          TYPE_B(24, 8)
          +-+-+-+-+-+-+-+-+
000000(D) |*| |* *|* * * *| char(1, 1) short(2, 2) int(4, 4) 
          +-+-+-+-+-+-+-+-+
000008(D) |* * * * * * * *| double(8, 8) 
          +-+-+-+-+-+-+-+-+
000016(D) |* * * *|* *|*|   int(4, 4) short(2, 2) char(1, 1) 
          +-+-+-+-+-+-+-+-+

          TYPE_C(32, 8)
          +-+-+-+-+-+-+-+-+
000000(D) |*|     |* * * *| char(1, 1) int(4, 4) 
          +-+-+-+-+-+-+-+-+
000008(D) |* * * * * * * *  TYPE_B(24, 8) 
          +-+-+-+-+-+-+-+-+
000016(D)  * * * * * * * *  
          +-+-+-+-+-+-+-+-+
000024(D)  * * * * * * * *| 
          +-+-+-+-+-+-+-+-+

          TYPE_PACK_DEFAULT(24, 8)
          +-+-+-+-+-+-+-+-+
000000(D) |*|     |* * * *| char(1, 1) int(4, 4) 
          +-+-+-+-+-+-+-+-+
000008(D) |* *|             short(2, 2) 
          +-+-+-+-+-+-+-+-+
000016(D) |* * * * * * * *| double(8, 8) 
          +-+-+-+-+-+-+-+-+

          TYPE_PACK_2(16, 2)
          +-+-+
000000(D) |*|   char(1, 1) 
          +-+-+
000002(D) |* *  int(4, 4) 
          +-+-+
000004(D)  * *| 
          +-+-+
000006(D) |* *| short(2, 2) 
          +-+-+
000008(D) |* *  double(8, 8) 
          +-+-+
000010(D)  * *  
          +-+-+
000012(D)  * *  
          +-+-+
000014(D)  * *| 
          +-+-+

          TYPE_PACK_16(24, 8)
          +-+-+-+-+-+-+-+-+
000000(D) |*|     |* * * *| char(1, 1) int(4, 4) 
          +-+-+-+-+-+-+-+-+
000008(D) |* *|             short(2, 2) 
          +-+-+-+-+-+-+-+-+
000016(D) |* * * * * * * *| double(8, 8) 
          +-+-+-+-+-+-+-+-+

```

## windows
```txt
_MSC_FULL_VER: 193833133
_MSVC_LANG: 202002
_WIN64: 1
__cplusplus: 199711


Fixed width integer types:
TYPE(SIZE): ALIGNMENT
--------------------
int8_t(1): 1
int16_t(2): 2
int32_t(4): 4
int64_t(8): 8
int_fast8_t(1): 1
int_fast16_t(4): 4
int_fast32_t(4): 4
int_fast64_t(8): 8
int_least8_t(1): 1
int_least16_t(2): 2
int_least32_t(4): 4
int_least64_t(8): 8
uint8_t(1): 1
uint16_t(2): 2
uint32_t(4): 4
uint64_t(8): 8
uint_fast8_t(1): 1
uint_fast16_t(4): 4
uint_fast32_t(4): 4
uint_fast64_t(8): 8
uint_least8_t(1): 1
uint_least16_t(2): 2
uint_least32_t(4): 4
uint_least64_t(8): 8
uintmax_t(8): 8
uintptr_t(8): 8


Other types:
TYPE(SIZE): ALIGNMENT
--------------------
size_t(8): 8
bool(1): 1
int(4): 4
short(2): 2
long(4): 4
long long(8): 8
float(4): 4
double(8): 8
long double(8): 8
char(1): 1
wchar_t(2): 2
ptrdiff_t(8): 8
nullptr_t(8): 1
max_align_t(8): 8


Example struct:
TYPE(SIZE, ALIGNMENT)
--------------------
          struct TYPE_0(1, 1)

          struct TYPE_A(64, 8)
          +-+-+-+-+-+-+-+-+
000000(D) |* * * *|*|*|     int(4, 4) char(1, 1) char(1, 1)
          +-+-+-+-+-+-+-+-+
000008(D) |* * * * * * * *| double(8, 8)
          +-+-+-+-+-+-+-+-+
000016(D) |*| |* *|         char(1, 1) short(2, 2)
          +-+-+-+-+-+-+-+-+
000024(D) |* * * * * * * *  class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >(40, 8)
          +-+-+-+-+-+-+-+-+
000032(D)  * * * * * * * *
          +-+-+-+-+-+-+-+-+
000040(D)  * * * * * * * *
          +-+-+-+-+-+-+-+-+
000048(D)  * * * * * * * *
          +-+-+-+-+-+-+-+-+
000056(D)  * * * * * * * *|
          +-+-+-+-+-+-+-+-+

          struct TYPE_B(24, 8)
          +-+-+-+-+-+-+-+-+
000000(D) |*| |* *|* * * *| char(1, 1) short(2, 2) int(4, 4)
          +-+-+-+-+-+-+-+-+
000008(D) |* * * * * * * *| double(8, 8)
          +-+-+-+-+-+-+-+-+
000016(D) |* * * *|* *|*|   int(4, 4) short(2, 2) char(1, 1)
          +-+-+-+-+-+-+-+-+

          struct TYPE_C(32, 8)
          +-+-+-+-+-+-+-+-+
000000(D) |*|     |* * * *| char(1, 1) int(4, 4)
          +-+-+-+-+-+-+-+-+
000008(D) |* * * * * * * *  struct TYPE_B(24, 8)
          +-+-+-+-+-+-+-+-+
000016(D)  * * * * * * * *
          +-+-+-+-+-+-+-+-+
000024(D)  * * * * * * * *|
          +-+-+-+-+-+-+-+-+

          struct TYPE_PACK_DEFAULT(24, 8)
          +-+-+-+-+-+-+-+-+
000000(D) |*|     |* * * *| char(1, 1) int(4, 4)
          +-+-+-+-+-+-+-+-+
000008(D) |* *|             short(2, 2)
          +-+-+-+-+-+-+-+-+
000016(D) |* * * * * * * *| double(8, 8)
          +-+-+-+-+-+-+-+-+

          struct TYPE_PACK_2(16, 2)
          +-+-+
000000(D) |*|   char(1, 1)
          +-+-+
000002(D) |* *  int(4, 4)
          +-+-+
000004(D)  * *|
          +-+-+
000006(D) |* *| short(2, 2)
          +-+-+
000008(D) |* *  double(8, 8)
          +-+-+
000010(D)  * *
          +-+-+
000012(D)  * *
          +-+-+
000014(D)  * *|
          +-+-+

          struct TYPE_PACK_16(24, 8)
          +-+-+-+-+-+-+-+-+
000000(D) |*|     |* * * *| char(1, 1) int(4, 4)
          +-+-+-+-+-+-+-+-+
000008(D) |* *|             short(2, 2)
          +-+-+-+-+-+-+-+-+
000016(D) |* * * * * * * *| double(8, 8)
          +-+-+-+-+-+-+-+-+

```