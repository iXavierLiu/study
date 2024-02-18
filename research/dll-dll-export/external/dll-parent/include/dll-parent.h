#pragma once

#ifndef _DLL_PARENT_API
#ifdef _WIN32
#define _DLL_PARENT_API __declspec(dllexport)
#elif defined __APPLE__ || defined __GNUC__
#define _DLL_PARENT_API __attribute__((dllexport))
#endif  //  _WIN32
#endif  // _DLL_PARENT_API

extern "C" _DLL_PARENT_API void dll_parent_c(int argc, char* argv[]);

class _DLL_PARENT_API dll_parent_cpp
{
public:
    static void fun(int argc, char* argv[]);
};

extern "C" _DLL_PARENT_API void test(int argc, char* argv[]);
