/*
 *
 * @file     1009.cpp
 * @author   errcodex
 * @brief
 * 4 cases passed on 9/3/2020 with 4ms max time use
 * and 424KB max space use.
 *
 */
#include <cstring>
#include <iostream>
#include <vector>

#pragma warning(disable : 4996)

using namespace std;

int main(int argc, char* argv[])
{
    char s[81];
    cin.getline(s, 81);
    char* token = strtok(s, " ");
    vector<string> v;
    while (token != NULL)
    {
        v.push_back(token);
        token = strtok(NULL, " ");
    }
    for (int i = v.size() - 1; i >= 0; --i)
    {
        cout << v[i];
        if (i != 0)
            cout << " ";
    }
    return 0;
}