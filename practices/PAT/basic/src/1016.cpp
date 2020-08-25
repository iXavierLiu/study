#include <iostream>
#include <sstream>
#include <vector>

using namespace std;



int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	int D; string A;
	int sum = 0;
	while (ss >> A) {
		int t = 0;
		ss >> D;
		for (auto c : A) {
			if (c - '0' == D) {
				t = t * 10 + D;
			}
		}
		sum += t;
	}
	cout << sum;
	return 0;
}
