#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;


void rebuild(int n, vector<uint8_t>& m) {
	m.clear();
	for(int i=0;i<4;i++){
		m.push_back(n % 10);
		n /= 10;
	}
	sort(m.begin(), m.end());
}
int calc(const vector<uint8_t>& n) {
	int ret = 0;
	for (auto i : n) {
		ret = ret * 10 + i;
	}
	return ret;
}
int main() {
	int N;
	cin >> N;
	vector<uint8_t> list;
	int t1, t2;
	bool newline = false;

	do {
		if (!newline) {
			newline = true;
		}
		else {
			cout << endl;
		}
		rebuild(N, list);
		t2 = calc(list);
		reverse(list.begin(), list.end());
		t1 = calc(list);
		
		cout << setw(4)<<setfill('0') <<t1 << " - " << setw(4) << setfill('0') << t2 << " = " << setw(4) << setfill('0') << t1 - t2;
		N=t1-t2;
	} while (!(N == 0 || N == 6174));//err: while(){}型循环会忽略输入为0和6173的输出，故用do-while
	return 0;
}
