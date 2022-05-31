#include <stdlib.h>
//#include "dll-parent.h"
#include "dll-sub.h"

int main(int argc, char* argv[])
{
	//dll_parent_c(argc, argv);

	//dll_parent_cpp::fun(argc, argv);

	//test(argc, argv);

	dll_sub_c(argc, argv);

	dll_sub_cpp::fun(argc, argv);

	return EXIT_SUCCESS;
}