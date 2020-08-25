#include <iostream>

using namespace std;

int main() {
    int n,count;
    cin >> n;
    count = 0;
    while (n != 1) {
        n = (n % 2) ? (3 * n + 1) / 2 : n / 2;
        ++count;
    }
    cout << count << endl;
    return 0;
}