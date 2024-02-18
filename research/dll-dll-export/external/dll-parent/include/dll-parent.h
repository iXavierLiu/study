#pragma once

#if !defined(_DLL_PARENT_API) && defined(_WIN32)
#define _DLL_PARENT_API __declspec(dllexport)
#else
#define _DLL_PARENT_API
#endif  //  !defined(_DLL_PARENT_API) && defined(_WIN32)

extern "C" _DLL_PARENT_API void dll_parent_c(int argc, char* argv[]);

class _DLL_PARENT_API dll_parent_cpp
{
public:
    static void fun(int argc, char* argv[]);
};

extern "C" _DLL_PARENT_API void test(int argc, char* argv[]);
