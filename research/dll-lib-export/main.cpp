#include "dll-sub.h"

#include <stdlib.h>
// #include "lib-sub.h"

int main(int argc, char* argv[])
{
    dll_sub_c(argc, argv);

    dll_sub_cpp::fun(argc, argv);

    // test(argc, argv);

    // lib_sub_c(argc, argv);

    // lib_sub_cpp::fun(argc, argv);

    return EXIT_SUCCESS;
}