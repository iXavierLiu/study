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
    static void _dump_block(size_t offset, size_t size)
    {
        std::cout << std::setw(offset * 2) << ""
                  << "|";

        for (size_t i = 0; i < size; i++)
        {
            std::cout << "* ";
        }

        std::cout << '\b';
    }
    static void _dump_left()
    {
        std::cout << std::setw(size_pointer + 1) << "";
    }

    static void _dump_left(size_t p)
    {
        std::cout << std::setw(size_pointer) << std::setfill('0') << p << std::setfill(' ') << " ";
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
        std::string type;
    };

    // get members info
    std::vector<MemberInfo> membersInfo;
    boost::pfr::for_each_field(T{}, [&membersInfo](auto& fields, size_t idx) {
        membersInfo.emplace_back(MemberInfo{ (size_t)&fields, sizeof(fields), boost::typeindex::type_id_runtime(fields).pretty_name() });
    });

    // set all info address begin from 0
    std::for_each(membersInfo.begin() + 1, membersInfo.end(), [&membersInfo](auto& item) { item.addr -= membersInfo.begin()->addr; });
    membersInfo.begin()->addr = 0;

    // output header
    std::cout << std::setw(size_pointer + 1) << "" << boost::typeindex::type_id_runtime(T{}).pretty_name() << "(" << width << ")" << std::endl;

    // output body
    auto it = membersInfo.begin();
    for (size_t i = 0; i < sizeof(T); i += width)
    {
        _dump_control(width);

        // dump block
        _dump_left(i);

        size_t linePos = 0;
        std::stringstream infoString;
        while (it != membersInfo.end() && it->addr < i + width)
        {
            _dump_block(it->addr - i - linePos, it->size);
            linePos += it->size;
            infoString << it->type << "(" << it->size << ") ";
            it++;
        }

        std::cout << "|" << std::setw((width - linePos) * 2 + 1) << "" << infoString.str() << std::endl;
    }

    _dump_control(width);
    std::cout << std::endl;
}
