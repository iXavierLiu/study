/*
 *
 * @file     1002.cpp
 * @author   errcodex
 * @brief
 * 6 cases passed on 9/3/2020 with 4ms max time use
 * and 512KB max space use.
 *
 */
#include <string.h>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    char n[101];
    cin.getline(n, 101);
    int count         = 0;
    const char* map[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (int len = strlen(n), i = 0; i < len; ++i)
    {
        count += n[i] - '0';
    }
    int m;
    for (int i = log10(count); i > 0; --i)
    {
        m = count / (int)pow(10, i);
        count %= (int)pow(10, i);
        cout << map[m] << " ";
    }
    cout << map[count % 10] << endl;
    return 0;
}