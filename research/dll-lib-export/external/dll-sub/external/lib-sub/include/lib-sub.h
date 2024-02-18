#pragma once

#ifndef _SYMBOL_DIRECTION
#ifdef LIB_SUB_EXPORTS
#define _SYMBOL_DIRECTION dllexport
#else
#define _SYMBOL_DIRECTION dllimport
#endif  // LIB_SUB_EXPORTS
#endif  //_SYMBOL_DIRECTION

#ifndef _LIB_SUB_API
#ifdef _WIN32
#define _LIB_SUB_API __declspec(_SYMBOL_DIRECTION)
#elif defined __APPLE__ || defined __GNUC__
#define _LIB_SUB_API __attribute__((_SYMBOL_DIRECTION))
#endif  //  _WIN32
#endif  // _LIB_SUB_API

extern "C" _LIB_SUB_API void lib_sub_c(int argc, char* argv[]);

class _LIB_SUB_API lib_sub_cpp
{
public:
    static void fun(int argc, char* argv[]);
};