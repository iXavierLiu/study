#include "dll-parent.h"
#include "dll-sub.h"
#include <iostream>
#define FUN(A,B) \
{\
std::cout<<__FUNCTION__<<std::endl<<"-----------"<<std::endl;\
for (int i = 0; i < argc; ++i)\
std::cout << i << ": " << argv[i] << std::endl;\
std::cout << "===========" << std::endl;\
};

void dll_parent_c(int argc, char* argv[])
{
	FUN(argc, argv);
}

void dll_parent_cpp::fun(int argc, char* argv[])
{
	FUN(argc, argv);
}

void test(int argc, char* argv[])
{
	dll_sub_c(argc,argv);
	dll_sub_cpp::fun(argc, argv);
}