#include <iostream>
#include <cmath>

using namespace std;

bool primeCheck(int n) {
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	if (n <= 1)return false;
	return true;
}

int main() {
	int N;
	cin >> N;
	int last = 2;
	int count = 0;
	for (int i = 3; i <= N; ++i) {
		if (primeCheck(i)) {
			if (i - last == 2) {
				count++;
			}
			last = i;
		}
	}
	cout << count;
	return 0;
}