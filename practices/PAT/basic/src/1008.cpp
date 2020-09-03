/*
 *
 * @file     1008.cpp
 * @author   errcodex
 * @brief
 * 5 cases passed on 9/3/2020 with 5ms max time use
 * and 424KB max space use.
 *
 */
#include <iostream>

using namespace std;

int gcd(const int a, const int b);

int main(int argc, char* argv[])
{
    int A[100], N, M;
    scanf("%d %d", &N, &M);
    M = M % N;
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);

    int t, pos, next;
    int d = gcd(N, M);
    for (int i = 0; i < d; i++)
    {
        t   = A[i];
        pos = i;
        do
        {
            next   = (pos - M + N) % N;
            A[pos] = A[next];
            if (next == i)
                break;
            pos = next;
        } while (true);
        A[pos] = t;
    }
    for (int i = 0; i < N; i++)
    {
        cout << A[i];
        if (i != N - 1)
            cout << " ";
    }
    return 0;
}

int gcd(const int a, const int b)
{
    return b == 0 ? a : gcd(b, a % b);
}