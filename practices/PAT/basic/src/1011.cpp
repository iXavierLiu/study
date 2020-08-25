#include <iostream>

using namespace std;
uint8_t sign(int n) {
	if (n == 0)return 0;
	return n > 0 ? 1 : -1;
}
int main(){
	int T, A, B, C;
	bool ans;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B >> C;
		ans = A + B > C;
		if ((sign(A) == sign(B)) && sign(A + B) != sign(A)) {//Òç³ö
			ans = sign(A) == 1 ? true : false;
		}
		cout << "Case #" << i + 1 << ": " << (ans ? "true" : "false") << endl;
	}
	return 0;
}