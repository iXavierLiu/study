#include <iostream>
#pragma warning(disable:4996)
using namespace std;

//非移动，只输出正确答案
void fun() {
	int A[100],N,M;
	scanf("%d %d", &N, &M);
	M = M % N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	if (M != N) {
		for (int i = N - M; i < N; ++i) {
			cout << A[i] << " ";
		}
	}
	for (int i = 0; i < N - M-1; ++i) {
		cout << A[i] << " ";
	}
	cout << A[N - M - 1];
}









int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
void fun2() {
	int A[100], N, M;
	scanf("%d %d", &N, &M);
	M = M % N;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}
	
	int t, pos, next;
	int d = gcd(N, M);
	for (int i = 0; i < d; i++)
	{
		t = A[i];
		pos = i;
		do {
			next = (pos - M +N) % N;
			A[pos] = A[next];
			if (next == i)break;
			pos = next;
		} while (true);
		A[pos] = t;
	}
	for (int i = 0; i < N; i++)
	{
		cout << A[i];
		if (i != N - 1)cout << " ";
	}
}
int main() {
	fun2();
	return 0;
}