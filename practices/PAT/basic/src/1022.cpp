/*
 *
 * @file     1022.cpp
 * @author   errcodex
 * @brief
 * 6 cases passed on 9/3/2020 with 5ms max time use
 * and 444KB max space use.
 *
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    unsigned int A, B, D, sum;
    cin >> A >> B >> D;
    sum = A + B;

    vector<int> output;

    do
    {
        output.push_back(sum % D);
        sum /= D;
    } while (sum != 0);  // err: while型循环当A+B=0时无输出，故改do-while

    for (auto i = output.rbegin(); i != output.rend(); i++)
        cout << *i;

    return 0;
}