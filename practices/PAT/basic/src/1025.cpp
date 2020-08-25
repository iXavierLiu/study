#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
class Node {
public:
	Node(const int& address, const int& data, const int& next) :address(address), data(data), next(next) {

	}
	int address, data, next;
	friend ostream& operator<<(ostream& out, const Node& node) {
		cout << setfill('0') << setw(5) << node.address << " " << node.data << " ";
		if (node.next == -1) {
			cout << node.next;
		}
		else {
			cout << setw(5) << node.next;
		}
		return out;
	}
	bool operator==(const int& n) {
		return address == n;
	}
};
int main() {
	int  first, N, K, add, data, next;
	cin >> first >> N >> K;
	vector<Node*> nodes;

	for (int i = 0; i < N; i++)
	{
		cin >> add >> data >> next;
		nodes.push_back(new Node(add, data, next));
	}

	for (int i = 0; i < N; i++) {//地址排序
		auto iter = find_if(nodes.begin() + i, nodes.end(), [&first](const Node* node)->bool {return first == node->address; });
		if (iter == nodes.end()) {//err: 绝B的坑，测试链表存在游离节点，要找到有多少个有效的节点N
			N = i; break;
		}
		if (i != iter - nodes.begin()) {//不为当前
			swap(nodes[i], nodes[iter - nodes.begin()]);
		}
		first = nodes[i]->next;
	}
	auto iter = nodes.begin();
	for (int i = 0; i + K <= N; i += K) {//K反转排序
		reverse(iter + i, iter + i + K);
	}
	for (int i = 1; i < N; i++) {//修改next
		nodes[i - 1]->next = nodes[i]->address;
	}
	nodes[N - 1]->next = -1;
	for_each(nodes.begin(), nodes.end(), [](auto iter) ->void {cout << *iter << endl; });
	for (auto node : nodes) {
		delete node;
	}
	//for_each(nodes.begin(), nodes.end(), [](vector<Node*>::iterator iter) ->void {auto i = *iter; delete i; });
	return 0;
}
//int main() {
//
//	int  first,N, K,add,data,next;
//	cin >> first >> N >> K;
//	vector<Node> v;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> add >> data >> next;
//		v.push_back(Node(add, data, next));
//	}
//	for (int i = 0; i < N; i++) {//地址排序
//		auto iter=find_if(v.begin()+i, v.end(), [&first](const Node& node)->bool {return first == node.address; });
//		if (iter == v.end()) {//err: 绝B的坑，测试链表存在游离节点，要找到有多少个有效的节点N
//			N = i; break;
//		}
//		if (i != iter-v.begin()) {//不为当前
//			swap(v[i], v[iter - v.begin()]);
//		}
//		first = v[i].next;
//	}
//
//	auto iter = v.begin();
//	for (int i = 0; i+K <= N; i+=K) {//K反转排序
//		reverse(iter+i, iter+i+K);
//	}
//	for (int i = 1; i < N; i++) {//修改next
//		v[i - 1].next = v[i].address;
//	}
//	v[N - 1].next = -1;
//
//	for (int i = 0; i < N; i++) {
//		cout << v[i] << endl;
//	}
//
//	return 0;
//}