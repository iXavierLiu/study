#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int main() {
	
	string line;
	getline(cin, line);
	stringstream ss(line);
	vector<int> v;
	int n;
	int t=0;
	while (ss >> n) {
		for (int i = 0; i < n; i++) {
			v.push_back(t);
		}
		t++;
	}
	sort(v.begin(), v.end());
	if (v[0] == 0) {
		for (auto i = v.begin();i!=v.end();i++) {
			if (*i == 0)continue;
			swap(v[0], *i); break;
		}
	}
	for (auto i : v) {
		cout << i;
	}
	return 0;
}