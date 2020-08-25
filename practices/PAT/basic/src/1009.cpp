#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
int main() {
	char s[81];
	cin.getline(s,81);
	char *token = strtok(s, " ");
	vector<string>v;
	while (token != NULL) {
		v.push_back(token);
		token=strtok(NULL, " ");
	}
	for (int i = v.size()-1; i >=0; --i)
	{
		cout << v[i];
		if (i != 0)cout << " ";
	}
	return 0;
}