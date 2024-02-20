#include "Utils.hpp"

#include <stdint.h>

struct TYPE_A
{
    int i0;
    char c1;
    int i1;
    double d0;
    char c2;
    char c3;
};
struct TYPE_B
{
    double a;
};

int main(int argc, char const* argv[])
{
    Utils::dump<TYPE_A>();
    return 0;
}
