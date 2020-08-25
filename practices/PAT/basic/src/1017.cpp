#include <iostream>
#include <vector>
using namespace std;


int main() {
	string A;
	int B;
	cin >> A >> B;
	int R=0;//余数
	vector<int> Q;//商
	for (auto c : A) {
		R = R * 10 + c - '0';
		Q.push_back(R / B);
		R = R % B;
	}
	
	for (auto i=Q.begin(); i != Q.end(); )
	{
		if (*i == 0) {
			i=Q.erase(i);//注意erase返回值的用法
			continue;
		}
		break;
	}
	for (auto i : Q) {
		cout << i;
	}
	if (Q.empty()) { cout << "0"; }//err: Q为空要输出0
	cout << " " << R;
	return 0;
}

