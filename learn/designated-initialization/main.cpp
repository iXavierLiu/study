#include <format>
#include <iostream>
#include <string>

struct S
{
    int intValue;
    std::string stringValue;
    double doubleValue;

    void print()
    {
        std::cout << intValue << stringValue << doubleValue << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    S s1 = { .intValue = 100, .stringValue = std::string(6, 's'), .doubleValue = 3.14 };
    s1.print();

    S s2 = { .stringValue = "fffff" };
    s2.print();

#ifndef _MSC_VER // msvc seems to not support for asignated initialization of array
    int a[3]{ [0] = 1, [1] = 11, [2] = 22 };
    for (auto &&i : a)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
#endif  // !_MSC_VER

    return 0;
}
