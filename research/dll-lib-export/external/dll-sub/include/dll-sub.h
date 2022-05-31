#pragma once

extern "C" __declspec(dllexport) void dll_sub_c(int argc, char* argv[]);

class __declspec(dllexport) dll_sub_cpp {
public:
	static void fun(int argc, char* argv[]);
};

extern "C" __declspec(dllexport) void test(int argc, char* argv[]);
