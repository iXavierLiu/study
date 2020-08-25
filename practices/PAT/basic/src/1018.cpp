#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp2(const pair<char, int>& p1, const pair<char, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first > p2.first;
	}
	return p1.second < p2.second;
}


int cmp(char t1, char t2) {
	if (t1 == t2) {
		return 0;
	}
	if ((t1 == 'C' && t2 == 'J') || (t1 == 'J' && t2 == 'B') || (t1 == 'B' && t2 == 'C')) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	int N;
	cin >> N;
	vector<char> w1, w2;
	vector<pair<char, int>> p1, p2;

	int win[3] = { 0 };
	char t1, t2, t;

	for (int i = 0; i < N; i++)
	{
		cin >> t1 >> t2;
		t = cmp(t1, t2);
		win[t + 1]++;
		if (t == 1) {
			w1.push_back(t1);
		}
		else if (t == -1) {
			w2.push_back(t2);
		}

	}

	p1.push_back(pair<char, int>('C', count(w1.begin(), w1.end(), 'C')));
	p1.push_back(pair<char, int>('J', count(w1.begin(), w1.end(), 'J')));
	p1.push_back(pair<char, int>('B', count(w1.begin(), w1.end(), 'B')));

	p2.push_back(pair<char, int>('C', count(w2.begin(), w2.end(), 'C')));
	p2.push_back(pair<char, int>('J', count(w2.begin(), w2.end(), 'J')));
	p2.push_back(pair<char, int>('B', count(w2.begin(), w2.end(), 'B')));

	sort(p1.begin(), p1.end(), cmp2);
	sort(p2.begin(), p2.end(), cmp2);

	cout << win[2] << " " << win[1] << " " << win[0] << endl;
	cout << win[0] << " " << win[1] << " " << win[2] << endl;
	cout << p1[2].first << " " << p2[2].first;
	return 0;
}
