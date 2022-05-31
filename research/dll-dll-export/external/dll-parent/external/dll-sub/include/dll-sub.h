#pragma once
#ifdef DLL_SUB_EXPORTS
extern "C" __declspec(dllexport)
#else
extern "C" __declspec(dllimport)
#endif
void dll_sub_c(int argc, char* argv[]);

class
#ifdef DLL_SUB_EXPORTS
__declspec(dllexport)
#else
__declspec(dllimport)
#endif
	dll_sub_cpp {
public:
	static void fun(int argc, char* argv[]);
};