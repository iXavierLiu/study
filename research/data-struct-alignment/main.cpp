#include "Utils.hpp"

#include <stdint.h>

struct DSA_1
{
    int i0;
    char c1;
    int i1;
    double d0;
};

int main(int argc, char const* argv[])
{
    Utils::dump<DSA_1>();
    return 0;
}
