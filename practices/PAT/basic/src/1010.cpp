#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	string line;
	getline(cin,line);
	stringstream ss(line);
	vector<int> list;
	int a,n;
	while (ss >> a) {
		ss >> n;
		if (!(a && n))continue;
		list.push_back(a * n);
		list.push_back(n - 1);
	}
	
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i];
		if (i != list.size() - 1)cout << " ";
	}
	if (list.empty()) {
		cout << "0 0";
	}
	return 0;
}