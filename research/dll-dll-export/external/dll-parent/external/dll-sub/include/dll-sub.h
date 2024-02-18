#pragma once

#if !defined(_DLL_SUB_API) && defined(_WIN32)
#if defined(DLL_SUB_EXPORTS)
#define _DLL_SUB_API __declspec(dllexport)
#else
#define _DLL_SUB_API __declspec(dllimport)
#endif  // defined(DLL_SUB_EXPORTS)
#else
#define _DLL_SUB_API
#endif  //  !defined(_DLL_SUB_API) && defined(_WIN32)

extern "C" _DLL_SUB_API void dll_sub_c(int argc, char* argv[]);

class _DLL_SUB_API dll_sub_cpp
{
public:
    static void fun(int argc, char* argv[]);
};