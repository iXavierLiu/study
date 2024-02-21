## macos
```txt
__APPLE__: 1
__aarch64__: 1
__cplusplus: 202002
__VERSION__: Apple LLVM 15.0.0 (clang-1500.1.0.2.5)


Fixed width integer types: 
TYPE(SIZE): ALIGNMENT
----------
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
----------
size_t(8): 8
size_t(8): 8
size_t(8): 8
size_t(8): 8
ptrdiff_t(8): 8
nullptr_t(8): 8
max_align_t(8): 8


Example struct:
TYPE(SIZE, ALIGNMENT)
----------
           TYPE_0(1, 1)

           TYPE_A(48, 8)
           +-+-+-+-+-+-+-+-+
0x00000000 |* * * *|*|*|     int(4, 4) char(1, 1) char(1, 1) 
           +-+-+-+-+-+-+-+-+
0x00000008 |* * * * * * * *| double(8, 8) 
           +-+-+-+-+-+-+-+-+
0x00000016 |*| |* *|         char(1, 1) short(2, 2) 
           +-+-+-+-+-+-+-+-+
0x00000024 |* * * * * * * *  std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>(24, 8) 
           +-+-+-+-+-+-+-+-+
0x00000032  * * * * * * * *  
           +-+-+-+-+-+-+-+-+
0x00000040  * * * * * * * *| 
           +-+-+-+-+-+-+-+-+

           TYPE_B(24, 8)
           +-+-+-+-+-+-+-+-+
0x00000000 |*| |* *|* * * *| char(1, 1) short(2, 2) int(4, 4) 
           +-+-+-+-+-+-+-+-+
0x00000008 |* * * * * * * *| double(8, 8) 
           +-+-+-+-+-+-+-+-+
0x00000016 |* * * *|* *|*|   int(4, 4) short(2, 2) char(1, 1) 
           +-+-+-+-+-+-+-+-+

           TYPE_C(32, 8)
           +-+-+-+-+-+-+-+-+
0x00000000 |*|     |* * * *| char(1, 1) int(4, 4) 
           +-+-+-+-+-+-+-+-+
0x00000008 |* * * * * * * *  TYPE_B(24, 8) 
           +-+-+-+-+-+-+-+-+
0x00000016  * * * * * * * *  
           +-+-+-+-+-+-+-+-+
0x00000024  * * * * * * * *| 
           +-+-+-+-+-+-+-+-+

           TYPE_PACK_DEFAULT(24, 8)
           +-+-+-+-+-+-+-+-+
0x00000000 |*|     |* * * *| char(1, 1) int(4, 4) 
           +-+-+-+-+-+-+-+-+
0x00000008 |* *|             short(2, 2) 
           +-+-+-+-+-+-+-+-+
0x00000016 |* * * * * * * *| double(8, 8) 
           +-+-+-+-+-+-+-+-+

           TYPE_PACK_2(16, 2)
           +-+-+
0x00000000 |*|   char(1, 1) 
           +-+-+
0x00000002 |* *  int(4, 4) 
           +-+-+
0x00000004  * *| 
           +-+-+
0x00000006 |* *| short(2, 2) 
           +-+-+
0x00000008 |* *  double(8, 8) 
           +-+-+
0x00000010  * *  
           +-+-+
0x00000012  * *  
           +-+-+
0x00000014  * *| 
           +-+-+

           TYPE_PACK_16(24, 8)
           +-+-+-+-+-+-+-+-+
0x00000000 |*|     |* * * *| char(1, 1) int(4, 4) 
           +-+-+-+-+-+-+-+-+
0x00000008 |* *|             short(2, 2) 
           +-+-+-+-+-+-+-+-+
0x00000016 |* * * * * * * *| double(8, 8) 
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
----------
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
----------
size_t(8): 8
size_t(8): 8
size_t(8): 8
size_t(8): 8
ptrdiff_t(8): 8
nullptr_t(8): 1
max_align_t(8): 8


Example struct:
TYPE(SIZE, ALIGNMENT)
----------
           struct TYPE_0(1, 1)

           struct TYPE_A(64, 8)
           +-+-+-+-+-+-+-+-+
0x00000000 |* * * *|*|*|     int(4, 4) char(1, 1) char(1, 1)
           +-+-+-+-+-+-+-+-+
0x00000008 |* * * * * * * *| double(8, 8)
           +-+-+-+-+-+-+-+-+
0x00000016 |*| |* *|         char(1, 1) short(2, 2)
           +-+-+-+-+-+-+-+-+
0x00000024 |* * * * * * * *  class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >(40, 8)
           +-+-+-+-+-+-+-+-+
0x00000032  * * * * * * * *
           +-+-+-+-+-+-+-+-+
0x00000040  * * * * * * * *
           +-+-+-+-+-+-+-+-+
0x00000048  * * * * * * * *
           +-+-+-+-+-+-+-+-+
0x00000056  * * * * * * * *|
           +-+-+-+-+-+-+-+-+

           struct TYPE_B(24, 8)
           +-+-+-+-+-+-+-+-+
0x00000000 |*| |* *|* * * *| char(1, 1) short(2, 2) int(4, 4)
           +-+-+-+-+-+-+-+-+
0x00000008 |* * * * * * * *| double(8, 8)
           +-+-+-+-+-+-+-+-+
0x00000016 |* * * *|* *|*|   int(4, 4) short(2, 2) char(1, 1)
           +-+-+-+-+-+-+-+-+

           struct TYPE_C(32, 8)
           +-+-+-+-+-+-+-+-+
0x00000000 |*|     |* * * *| char(1, 1) int(4, 4)
           +-+-+-+-+-+-+-+-+
0x00000008 |* * * * * * * *  struct TYPE_B(24, 8)
           +-+-+-+-+-+-+-+-+
0x00000016  * * * * * * * *
           +-+-+-+-+-+-+-+-+
0x00000024  * * * * * * * *|
           +-+-+-+-+-+-+-+-+

           struct TYPE_PACK_DEFAULT(24, 8)
           +-+-+-+-+-+-+-+-+
0x00000000 |*|     |* * * *| char(1, 1) int(4, 4)
           +-+-+-+-+-+-+-+-+
0x00000008 |* *|             short(2, 2)
           +-+-+-+-+-+-+-+-+
0x00000016 |* * * * * * * *| double(8, 8)
           +-+-+-+-+-+-+-+-+

           struct TYPE_PACK_2(16, 2)
           +-+-+
0x00000000 |*|   char(1, 1)
           +-+-+
0x00000002 |* *  int(4, 4)
           +-+-+
0x00000004  * *|
           +-+-+
0x00000006 |* *| short(2, 2)
           +-+-+
0x00000008 |* *  double(8, 8)
           +-+-+
0x00000010  * *
           +-+-+
0x00000012  * *
           +-+-+
0x00000014  * *|
           +-+-+

           struct TYPE_PACK_16(24, 8)
           +-+-+-+-+-+-+-+-+
0x00000000 |*|     |* * * *| char(1, 1) int(4, 4)
           +-+-+-+-+-+-+-+-+
0x00000008 |* *|             short(2, 2)
           +-+-+-+-+-+-+-+-+
0x00000016 |* * * * * * * *| double(8, 8)
           +-+-+-+-+-+-+-+-+

```