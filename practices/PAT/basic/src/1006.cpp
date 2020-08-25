#include <iostream>
#include <cmath>
using namespace std;
char map[] = { ' ','S','B' };
int main() {
	int num;
	cin >> num;
	for (int len = log10(num), i = len; i > 0; --i) {
		for (int j = 0, k = num / (int)pow(10, i); j < k; ++j) {
			cout << map[i];
		}
		num %= (int)pow(10, i);
	}
	for (int i = 0, t = num % 10; i < t; ++i) {
		cout << i+1;
	}
	return 0;
}