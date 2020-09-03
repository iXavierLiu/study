/*
 *
 * @file     1003.cpp
 * @author   errcodex
 * @brief
 * 6 cases passed on 9/3/2020 with 4ms max time use
 * and 424KB max space use.
 *
 */
#include <iostream>

using namespace std;

bool f(const string& s);

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cout << (f(s) ? "YES" : "NO");
        if (i != n - 1)
            cout << endl;
    }
    return 0;
}

bool f(const string& s)
{
    char map[]    = {'P', 'T', '\0'};
    char count[3] = {0};
    int exp       = 0;
    for (auto i : s)
    {
        if (!(i == 'P' || i == 'A' || i == 'T'))
        {
            return false;
        }
        if (i == map[exp])
        {
            exp++;
        }
        else if (i == 'A')
        {
            count[exp]++;
        }
        else
        {
            return false;
        }
    }
    if (map[exp] != '\0')
        return false;  // err: 必须读取完所有期待字符
    if (count[1] > 0 && count[0] * count[1] == count[2])
    {
        return true;
    }
    return false;
}