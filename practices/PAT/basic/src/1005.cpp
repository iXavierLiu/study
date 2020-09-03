/*
 *
 * @file     1005.cpp
 * @author   errcodex
 * @brief
 * 5 cases passed on 9/3/2020 with 4ms max time use
 * and 512KB max space use.
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>

#pragma warning(disable : 4996)

using namespace std;

void guess(int n, vector<int>& out);
bool check(const int n, const vector<int>& v);
void print(const vector<int>& v);

int main(int argc, char* argv[])
{
    int count, n;
    vector<int> list;
    vector<int> verified;
    vector<int> out;
    if (scanf("%d", &count))
        ;

    for (int i = 0; i < count; ++i)
    {
        if (scanf("%d", &n))
            ;

        list.push_back(n);
        if (!check(n, verified))
        {
            guess(n, verified);
        }
    }
    //ШЅжи
    sort(verified.begin(), verified.end());
    vector<int>::iterator it = unique(verified.begin(), verified.end());
    verified.erase(it, verified.end());

    for (int i = 0; i < count; ++i)
    {
        int n = list[i];
        if (!check(n, verified))
        {
            out.push_back(n);
        }
    }

    sort(out.rbegin(), out.rend());
    print(out);

    return 0;
}

void guess(int n, vector<int>& out)
{
    // out.push_back(n);
    while (n != 1)
    {
        n = (n % 2) ? (3 * n + 1) / 2 : n / 2;
        out.push_back(n);
    }
}
bool check(const int n, const vector<int>& v)
{
    for (int i = 0, len = v.size(); i < len; ++i)
        if (n == v[i])
            return true;
    return false;
}
void print(const vector<int>& v)
{
    for (int i = 0, len = v.size(); i < len - 1; ++i)
        cout << v[i] << " ";
    if (v.size() > 0)
        cout << v[v.size() - 1];
}