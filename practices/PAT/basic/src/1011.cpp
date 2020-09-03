/*
 *
 * @file     1011.cpp
 * @author   errcodex
 * @brief
 * 3 cases passed on 9/3/2020 with 3ms max time use
 * and 424KB max space use.
 *
 */
#include <iostream>

using namespace std;

int sign(const int n);

int main(int argc, char* argv[])
{
    int T, A, B, C;
    bool ans;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B >> C;
        ans = A + B > C;
        if ((sign(A) == sign(B)) && sign(A + B) != sign(A))
        {  //??
            ans = sign(A) == 1 ? true : false;
        }
        cout << "Case #" << i + 1 << ": " << (ans ? "true" : "false") << endl;
    }
    return 0;
}

int sign(const int n)
{
    if (!n)
        return 0;
    return n > 0 ? 1 : -1;
}