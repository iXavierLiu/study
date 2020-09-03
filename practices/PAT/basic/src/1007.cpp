/*
 *
 * @file     1007.cpp
 * @author   errcodex
 * @brief
 * 6 cases passed on 9/3/2020 with 19ms max time use
 * and 372KB max space use.
 *
 */
#include <cmath>
#include <iostream>

using namespace std;

bool primeCheck(const int n);

int main(int argc, char* argv[])
{
    int N;
    cin >> N;
    int last  = 2;
    int count = 0;

    for (int i = 3; i <= N; ++i)
    {
        if (primeCheck(i))
        {
            if (i - last == 2)
                count++;
            last = i;
        }
    }

    cout << count;
    return 0;
}

bool primeCheck(const int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;

    if (n <= 1)
        return false;
    return true;
}