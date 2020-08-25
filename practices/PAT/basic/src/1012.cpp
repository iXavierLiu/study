#include <iostream>
#include  <sstream>
#include <iomanip>

using namespace std;

int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	int n, m, c2 = 1, c4 = 0, c2_flag = 0;
	int a[5] = { 0 };
	ss >> n;
	while (ss >> n) {
		m = n % 5;
		switch (m)//余数
		{
		case 0:
			if (n % 2 == 0) { a[0] += n; }break;
		case 1:
			a[1] += c2 * n; c2 *= -1; c2_flag++; break;
		case 2:
			a[2]++; break;
		case 3:
			c4++; a[3] += n; break;
		case 4:
			if (n > a[4]) { a[4] = n; }break;
		}
	}
	/*cout << a[3] << " " << c4 << endl;*/
	if (a[0] == 0) {
		cout << "N ";
	}
	else {
		cout << a[0] << " ";
	}

	if (c2_flag == 0) {
		cout << "N ";
	}
	else {
		cout << a[1] << " ";
	}
	if (a[2] == 0) {
		cout << "N ";
	}
	else {
		cout << a[2] << " ";
	}
	if (a[3] == 0 || c4 == 0) {
		cout << "N ";
	}
	else {
		cout<< fixed << setprecision(1) << (float)a[3] / c4 << " " ;
	}
	if (a[4] == 0) {
		cout << "N";
	}
	else {
		cout << a[4];
	}


	return 0;
}

