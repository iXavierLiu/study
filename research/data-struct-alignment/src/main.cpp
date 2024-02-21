#include "Utils.hpp"

#include <cstdint>

#define MACRO_OUTPUT(p) std::cout << #p << ": " << p << std::endl;
#define TYPE_OUTPUT(p) std::cout << #p << "(" << sizeof(p) << "): " << alignof(p) << std::endl;

struct TYPE_0
{
};

struct TYPE_A
{
    int i0;
    char c0, c1;
    double d0;
    char c2;
    short si0;
    std::string s;
};

struct TYPE_B
{
    char c0;
    short s0;
    int i0;
    double d0;
    int i1;
    short s1;
    char c1;
};

struct TYPE_C
{
    char c0;
    int i0;
    TYPE_B a;
};

struct TYPE_PACK_DEFAULT
{
    char c0;
    int i0;
    short s0;
    double d0;
};

#pragma pack(push, 2)

struct TYPE_PACK_2
{
    char c0;
    int i0;
    short s0;
    double d0;
};

#pragma pack(pop)

#pragma pack(push, 16)

struct TYPE_PACK_16
{
    char c0;
    int i0;
    short s0;
    double d0;
};

#pragma pack(pop)

int main(int argc, char const* argv[])
{
    // https://developer.apple.com/library/archive/documentation/Porting/Conceptual/PortingUnix/compiling/compiling.html#//apple_ref/doc/uid/TP40002850-SW13
    // https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170
    // https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html

#ifdef _MSC_VER
    MACRO_OUTPUT(_MSC_FULL_VER);
    MACRO_OUTPUT(_MSVC_LANG);
#ifdef _WIN64
    MACRO_OUTPUT(_WIN64);
#else
    MACRO_OUTPUT(_WIN32);
#endif  //_WIN64
#endif  //_MSC_VER

#ifdef __APPLE__
    MACRO_OUTPUT(__APPLE__);
#endif

#ifdef __x86_64__
    MACRO_OUTPUT(__x86_64__);
#elif defined(__i386__)
    MACRO_OUTPUT(__i386__);
#elif defined(__amd64__)
    MACRO_OUTPUT(__amd64__);
#elif defined(__arm__)
    MACRO_OUTPUT(__arm__);
#elif defined(__aarch64__)
    MACRO_OUTPUT(__aarch64__);
#endif

    MACRO_OUTPUT(__cplusplus);

#ifdef __VERSION__
    MACRO_OUTPUT(__VERSION__);
#endif

    std::cout << std::endl << std::endl << "Fixed width integer types: \nTYPE(SIZE): ALIGNMENT\n----------" << std::endl;
    TYPE_OUTPUT(int8_t);
    TYPE_OUTPUT(int16_t);
    TYPE_OUTPUT(int32_t);
    TYPE_OUTPUT(int64_t);

    TYPE_OUTPUT(int_fast8_t);
    TYPE_OUTPUT(int_fast16_t);
    TYPE_OUTPUT(int_fast32_t);
    TYPE_OUTPUT(int_fast64_t);

    TYPE_OUTPUT(int_least8_t);
    TYPE_OUTPUT(int_least16_t);
    TYPE_OUTPUT(int_least32_t);
    TYPE_OUTPUT(int_least64_t);

    TYPE_OUTPUT(uint8_t);
    TYPE_OUTPUT(uint16_t);
    TYPE_OUTPUT(uint32_t);
    TYPE_OUTPUT(uint64_t);

    TYPE_OUTPUT(uint_fast8_t);
    TYPE_OUTPUT(uint_fast16_t);
    TYPE_OUTPUT(uint_fast32_t);
    TYPE_OUTPUT(uint_fast64_t);

    TYPE_OUTPUT(uint_least8_t);
    TYPE_OUTPUT(uint_least16_t);
    TYPE_OUTPUT(uint_least32_t);
    TYPE_OUTPUT(uint_least64_t);

    TYPE_OUTPUT(uintmax_t);
    TYPE_OUTPUT(uintptr_t);

#if 0
#include <stdfloat>
    std::cout << std::endl << std::endl << "Fixed width floating-point types: \nTYPE(SIZE): ALIGNMENT\n----------" << std::endl;
    TYPE_OUTPUT(std::float16_t);
    TYPE_OUTPUT(std::float32_t);
    TYPE_OUTPUT(std::float64_t);
    TYPE_OUTPUT(std::float128_t);
    TYPE_OUTPUT(std::bfloat16_t);
#endif

    std::cout << std::endl << std::endl << "Other types: \nTYPE(SIZE): ALIGNMENT\n----------" << std::endl;
    TYPE_OUTPUT(size_t);
    TYPE_OUTPUT(size_t);
    TYPE_OUTPUT(size_t);
    TYPE_OUTPUT(size_t);
    TYPE_OUTPUT(ptrdiff_t);
    TYPE_OUTPUT(nullptr_t);
    TYPE_OUTPUT(max_align_t);

    std::cout << std::endl << std::endl << "Example struct:\nTYPE(SIZE, ALIGNMENT)\n----------" << std::endl;
    Utils::dump<TYPE_0>();
    Utils::dump<TYPE_A>();
    Utils::dump<TYPE_B>();
    Utils::dump<TYPE_C>();
    Utils::dump<TYPE_PACK_DEFAULT>();
    Utils::dump<TYPE_PACK_2>();
    Utils::dump<TYPE_PACK_16>();

    return 0;
}
