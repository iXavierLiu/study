#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;
class Cake {
public:
	Cake(const double& store, const double& price) :store(store), price(price) {
		avgPrice = price / store;
	}
	bool operator<(const Cake& cake) {
		return avgPrice < cake.avgPrice;
	}
	double price, avgPrice, store;//err: 注意N,D是正整数，库存和总价都是正数
};


int main() {
	int N, D;
	double t1,t2;
	cin >> N >> D;
	vector<Cake> cakes;

	cin.get();
	string line;
	getline(cin, line);
	stringstream ss1(line);
	getline(cin, line);
	stringstream ss2(line);


	for (int i = 0; i < N; i++) {
		ss1 >> t1;
		ss2 >> t2;
		cakes.push_back(Cake(t1, t2));
	}

	sort(cakes.rbegin(), cakes.rend());

	double money = 0;
	for (auto i = cakes.begin(); i != cakes.end(); i++) {
		if (D < i->store) {
			money += D * i->avgPrice; break;
		}
		money += i->price;
		D -= i->store;
	}
	cout << fixed << setprecision(2) << money;
	return 0;
}
