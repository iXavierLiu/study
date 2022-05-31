#include "dll-sub.h"
#include "lib-sub.h"
#include <iostream>
#define FUN(A,B) \
{\
std::cout<<__FUNCTION__<<std::endl<<"-----------"<<std::endl;\
for (int i = 0; i < argc; ++i)\
std::cout << i << ": " << argv[i] << std::endl;\
std::cout << "===========" << std::endl;\
};

void dll_sub_c(int argc, char* argv[])
{
	FUN(argc, argv);
}

void dll_sub_cpp::fun(int argc, char* argv[])
{
	FUN(argc, argv);
}

void test(int argc, char* argv[])
{
	lib_sub_c(argc,argv);
	lib_sub_cpp::fun(argc, argv);
}