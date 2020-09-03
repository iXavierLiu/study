/*
 *
 * @file     1006.cpp
 * @author   errcodex
 * @brief
 * 9 cases passed on 9/3/2020 with 4ms max time use
 * and 384KB max space use.
 *
 */
#include <cmath>
#include <iostream>

using namespace std;

const char map[] = {' ', 'S', 'B'};

int main(int argc, char* argv[])
{
    int num;
    cin >> num;

    for (int len = log10(num), i = len; i > 0; --i)
    {
        for (int j = 0, k = num / (int)pow(10, i); j < k; ++j)
            cout << map[i];
        num %= (int)pow(10, i);
    }

    for (int i = 0, t = num % 10; i < t; ++i)
        cout << i + 1;

    return 0;
}