module;
#include <iostream>

export module test:impl;
import hello;

class TestImpl
{
public:
    TestImpl()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

    void Foo() {
        std::cout << __FUNCTION__ << std::endl;
    }
};