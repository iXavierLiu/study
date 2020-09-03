/*
 *
 * @file     1021.cpp
 * @author   errcodex
 * @brief
 * 3 cases passed on 9/3/2020 with 3ms max time use
 * and 384KB max space use.
 *
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    vector<bool> dig[10];
    string line;
    getline(cin, line);
    for (auto i : line)
        dig[i - '0'].push_back(true);

    for (int i = 0; i < 10; i++)
    {
        if (dig[i].size() == 0)
            continue;
        cout << i << ":" << dig[i].size() << endl;
    }
    return 0;
}