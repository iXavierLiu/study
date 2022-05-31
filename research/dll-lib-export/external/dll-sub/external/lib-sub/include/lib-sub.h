#pragma once
#ifdef LIB_SUB_EXPORTS
extern "C" __declspec(dllexport)
#else
extern "C" __declspec(dllimport)
#endif
void lib_sub_c(int argc, char* argv[]);

class
#ifdef LIB_SUB_EXPORTS
__declspec(dllexport)
#else
__declspec(dllimport)
#endif
	lib_sub_cpp {
public:
	static void fun(int argc, char* argv[]);
};