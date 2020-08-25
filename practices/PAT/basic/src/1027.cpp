#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
class Node {
public:
	int data, next;
};
int main() {
	int  first, N, K, t;
	vector<Node> nodes(100000);
	vector<int>result(100000);
	cin >> first >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		cin >> nodes[t].data >> (nodes[t].next);
	}
	for (int i = 0; i < N; i++) {//地址排序
		if (first == -1) {//err: 绝B的坑，测试链表存在游离节点，要找到有多少个有效的节点N
			N = i; break;
		}
		result[i] = first;
		first = nodes[first].next;
	}
	for (int i = 0; i < N - N % K; i+=K) {
		reverse(result.begin()+i, result.begin()+i+K);
	}
	for (int i = 0; i < N-1; i++)
	{
		printf("%05d %d %05d\n", result[i], nodes[result[i]].data, result[i + 1]);
		//cout << setfill('0') << setw(5) << result[i] << " " << nodes[result[i]].data << " " << setw(5) << result[i+1]<< endl;
	}
	printf("%05d %d -1\n", result[N-1], nodes[result[N-1]].data);

	//cout << setfill('0') << setw(5) << result[N-1] << " " << nodes[result[N-1]].data << " -1";

	return 0;
}