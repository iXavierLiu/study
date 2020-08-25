#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Stu {
public:
	Stu(const int& no, const int& de, const int& cai, const int& L, const int& H) :no(no), de(de), cai(cai) {
		total = de + cai;
		pass = de >= L && cai >= L ? 1 : 0;
		if (!pass)return;
		if (de >= H && cai >= H) {
			level = 1;
		}
		else if (de >= H && cai < H) {
			level = 2;
		}
		else if (de < H && cai < H && de >= cai) {
			level = 3;
		}
		else {
			level = 4;
		}
	}

	bool operator< (const Stu& s) {
		if (total != s.total) {//½µÐò
			return total > s.total;
		}
		else if (de != s.de) {
			return de > s.de;
		}
		return no < s.no;//ÉýÐò
	}
	friend ostream& operator<<(ostream& output, const Stu& stu) {
		output << stu.no << " " << stu.de << " " << stu.cai;
		return output;
	}

	int no;
	int de, cai, total;
	int level;
	bool pass;
};



int main() {
	string line;
	int count, L, H;
	cin >> count >> L >> H;
	vector<Stu> list[4];
	int no, de, cai;
	for (int i = 0; i < count; i++) {
		cin >> no >> de >> cai;
		Stu stu(no, de, cai, L, H);
		if (!stu.pass)continue;
		list[stu.level - 1].push_back(Stu(stu));
	}
	int n = 0;
	for (int i = 0; i < 4; i++) {
		n += list[i].size();
		sort(list[i].begin(), list[i].end());
	}

	cout << n << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < list[i].size(); j++) {
			cout << list[i][j];
			if (!(i == 3 && j == list[i].size() - 1))cout << endl;
		}
	}
	return 0;
}


