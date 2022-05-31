#include "lib-sub.h"
#include <iostream>
#define FUN(A,B) \
{\
std::cout<<__FUNCTION__<<std::endl<<"-----------"<<std::endl;\
for (int i = 0; i < argc; ++i)\
std::cout << i << ": " << argv[i] << std::endl;\
std::cout << "===========" << std::endl;\
};

void lib_sub_c(int argc, char* argv[])
{
	FUN(argc, argv);
}

void lib_sub_cpp::fun(int argc, char* argv[])
{
	FUN(argc, argv);
}
