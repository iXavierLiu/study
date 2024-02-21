#pragma once
#include <boost/pfr.hpp>
#include <boost/type_index.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

class Utils
{
public:
    template <typename T>
    static void dump();

private:
    static size_t size_pointer;

    static void _dump_control(size_t width)
    {
        _dump_left();
        for (size_t i = 0; i < width; i++)
        {
            std::cout << "+-";
        }
        std::cout << "+" << std::endl;
    }

    static void _dump_left()
    {
        std::cout << "  " << std::setw(size_pointer + 1) << "";
    }

    static void _dump_left(size_t p)
    {
        std::cout << "0x" << std::setw(size_pointer) << std::setfill('0') << p << std::setfill(' ') << " ";
    }
};

size_t Utils::size_pointer = sizeof(void*);

template <typename T>
void Utils::dump()
{
    size_t width = alignof(T);

    struct MemberInfo
    {
        size_t addr;
        size_t size;
        size_t align;
        std::string type;
    };

    // get members info
    std::vector<MemberInfo> membersInfo;
    boost::pfr::for_each_field(T{}, [&membersInfo](auto& fields, size_t idx) {
        membersInfo.emplace_back(MemberInfo{ (size_t)&fields, sizeof(fields), alignof(decltype(fields)), boost::typeindex::type_id_runtime(fields).pretty_name() });
    });

    // output header
    _dump_left();
    std::cout << boost::typeindex::type_id_runtime(T{}).pretty_name() << "(" << sizeof(T) << ", " << width << ")" << std::endl;

    // set all info address begin from 0
    if (!membersInfo.size())
    {
        std::cout << std::endl;
        return;
    }

    std::for_each(membersInfo.begin() + 1, membersInfo.end(), [&membersInfo](auto& item) { item.addr -= membersInfo.begin()->addr; });
    membersInfo.begin()->addr = 0;

    // output body
    auto it = membersInfo.begin();

    std::stringstream typeString;
    for (size_t pos = 0; pos < sizeof(T); pos++)
    {
        if (pos % width == 0)
        {
            if (pos) std::cout << " " << typeString.str() << std::endl;
            _dump_control(width);
            _dump_left(pos);

            typeString.str("");
        }

        if (pos > it->addr + it->size - 1) ++it;
        if (it == membersInfo.end())
        {
            std::cout << "  ";
            continue;
        }

        if (pos > it->addr)
        {
            if (pos % width == 0) std::cout << " ";
            std::cout << "* ";
            if (pos == it->addr + it->size - 1) std::cout << "\b|";
        }
        else if (pos == it->addr)
        {
            if (pos % width != 0) std::cout << "\b";
            std::cout << "|* ";
            if (it->size == 1) std::cout << "\b|";
            typeString << it->type << "(" << it->size << ", " << it->align << ") ";
        }
        else
        {
            std::cout << "  ";
        }
    }
    std::cout << " " << typeString.str() << std::endl;

    _dump_control(width);
    std::cout << std::endl;
}
