#pragma once

#if !defined(_LIB_SUB_API) && defined(_WIN32)
#if defined(LIB_SUB_EXPORTS)
#define _LIB_SUB_API __declspec(dllexport)
#else
#define _LIB_SUB_API __declspec(dllimport)
#endif  // defined(LIB_SUB_EXPORTS)
#else
#define _LIB_SUB_API
#endif  //  _WIN32

extern "C" _LIB_SUB_API void lib_sub_c(int argc, char* argv[]);

class _LIB_SUB_API lib_sub_cpp
{
public:
    static void fun(int argc, char* argv[]);
};