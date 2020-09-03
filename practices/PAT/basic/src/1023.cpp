/*
 *
 * @file     1023.cpp
 * @author   errcodex
 * @brief
 * 5 cases passed on 9/3/2020 with 4ms max time use
 * and 424KB max space use.
 *
 */
#include <algorithm>
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
    vector<int> v;
    int n;
    int t = 0;
    while (ss >> n)
    {
        for (int i = 0; i < n; i++)
            v.push_back(t);
        t++;
    }
    sort(v.begin(), v.end());
    if (v[0] == 0)
    {
        for (auto i = v.begin(); i != v.end(); i++)
        {
            if (*i == 0)
                continue;
            swap(v[0], *i);
            break;
        }
    }
    for (auto i : v)
        cout << i;

    return 0;
}