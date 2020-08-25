#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main() {
	vector<bool> dig[10];
	string line;
	getline(cin, line);
	for (auto i : line) {
		dig[i - '0'].push_back(true);
	}

	for (int i = 0; i < 10; i++) {
		if (dig[i].size() == 0)continue;
		cout << i << ":" << dig[i].size() << endl;
	}
	return 0;
}