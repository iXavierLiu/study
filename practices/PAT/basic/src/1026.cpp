#include <iostream>
#include <iomanip>
using namespace std;
class Point {
public:
	Point() :x(0), y(0) {}
	Point(const int& x, const int& y) :x(x), y(y) {}
	//一元
	Point operator-() {//-point
		return Point(-x, -y);
	}
	Point operator++() {//++point
		++x; ++y;
		return *this;
	}
	int& operator[](size_t pos) {
		return pos ? y : x;
	}
	const Point operator++(int) {//point++ -> operator++(0) 后缀表达式可以加const
		Point p= *this;
		++x; ++y;
		return p;
	}
	//二元
	Point operator+(const Point& p) {//p1+p2 -> p1.operator+(p2)
		return Point(x + p.x, y + p.y);
	}
	bool operator==(const Point& p) {
		return x == p.x && y == p.y;
	}
	friend ostream& operator<<(ostream& out,const Point& p) {
		out << "{ x:" << p.x << ", y: " << p.y << " }"<<endl;
		return out;
	}
	friend istream& operator>>(istream& in, Point& p) {
		in >> p.x >> p.y;
		return in;
	}
	int x, y;
};
int main() {
	Point p;
	cout <<setw(25)<< "cout<<p: " << p;
	cin >> p;// 1 2
	cout << setw(25) << "cin>>p: "<< p;
	cout << setw(25) << "p++: " << p++;
	cout << setw(25) << "now p: " << p;
	cout<< setw(25) << "++p: "<< ++p;
	cout << setw(25) << "now p: " << p;
	cout << setw(25) << "p[0]: "<<p[0]<<endl;
	cout << setw(25) << "-p: "<< -p;
	cout << setw(25) << "Point(3,4)+Point(5,6): " << Point(3, 4) + Point(5, 6);
	cout << setw(25) << "Point(3,4)==Point(5,6): " << (Point(3, 4) == Point(5, 6));

	return 0;
}