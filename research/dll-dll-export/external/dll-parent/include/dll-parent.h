#pragma once

extern "C" __declspec(dllexport) void dll_parent_c(int argc, char* argv[]);

class __declspec(dllexport) dll_parent_cpp {
public:
	static void fun(int argc, char* argv[]);
};

extern "C" __declspec(dllexport) void test(int argc, char* argv[]);
