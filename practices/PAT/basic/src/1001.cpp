/*
 *
 * @file     1001.cpp
 * @author   errcodex
 * @brief
 * 5 cases passed on 9/3/2020 with 4ms max time use
 * and 384KB max space use.
 *
 */
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int n, count;
    cin >> n;
    count = 0;
    while (n != 1)
    {
        n = (n % 2) ? (3 * n + 1) / 2 : n / 2;
        ++count;
    }
    cout << count << endl;
    return 0;
}