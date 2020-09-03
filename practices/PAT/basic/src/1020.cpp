/*
 *
 * @file     1020.cpp
 * @author   errcodex
 * @brief
 * 5 cases passed on 9/3/2020 with 5ms max time use
 * and 424KB max space use.
 *
 */
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Cake
{
public:
    Cake(const double& store, const double& price);
    bool operator<(const Cake& cake);
    double price, avgPrice, store;  // err: 注意N,D是正整数，库存和总价都是正数
};

int main(int argc, char* argv[])
{
    int N, D;
    double t1, t2;
    cin >> N >> D;
    vector<Cake> cakes;

    cin.get();
    string line;
    getline(cin, line);
    stringstream ss1(line);
    getline(cin, line);
    stringstream ss2(line);

    for (int i = 0; i < N; i++)
    {
        ss1 >> t1;
        ss2 >> t2;
        cakes.push_back(Cake(t1, t2));
    }

    sort(cakes.rbegin(), cakes.rend());

    double money = 0;
    for (auto i = cakes.begin(); i != cakes.end(); i++)
    {
        if (D < i->store)
        {
            money += D * i->avgPrice;
            break;
        }
        money += i->price;
        D -= i->store;
    }
    cout << fixed << setprecision(2) << money;
    return 0;
}

Cake::Cake(const double& store, const double& price) : store(store), price(price)
{
    avgPrice = price / store;
}
bool Cake::operator<(const Cake& cake)
{
    return avgPrice < cake.avgPrice;
}