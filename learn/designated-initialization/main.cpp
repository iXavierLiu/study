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
    S s1 = { .stringValue = std::string(6, 's'), .doubleValue = 3.14, .intValue = 100 };
    s1.print();

    S s2 = { .stringValue = "fffff" };
    s2.print();

    int a[3]{ [1] = 99 };
    for (auto &&i : a)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
