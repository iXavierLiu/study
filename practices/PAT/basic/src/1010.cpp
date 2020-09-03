/*
 *
 * @file     1010.cpp
 * @author   errcodex
 * @brief
 * 5 cases passed on 9/3/2020 with 6ms max time use
 * and 496KB max space use.
 *
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> list;
    int a, n;

    while (ss >> a)
    {
        ss >> n;
        if (!(a && n))
            continue;
        list.push_back(a * n);
        list.push_back(n - 1);
    }

    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i];
        if (i != list.size() - 1)
            cout << " ";
    }

    if (list.empty())
        cout << "0 0";

    return 0;
}