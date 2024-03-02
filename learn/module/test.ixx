module;
#include <iostream>
export module test;

import :impl;

export class Test : private TestImpl
{
public:
    Test()
    {
        std::cout << __FUNCTION__ << std::endl;
    }

    void Bar()
    {
        Foo();
        // Hello();
    }
};