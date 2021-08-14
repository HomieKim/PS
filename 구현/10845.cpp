#include <iostream>
#include <queue>

using namespace std;


int main() {
	int n;
	cin >> n;

	queue<int> que;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			que.push(num);
		}
		else if (str == "pop") {
			if (!que.empty()) {
				cout << que.front() << endl;
				que.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (str == "size") {
			cout << que.size() << endl;
		}
		else if (str == "empty") {
			if (que.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (str == "front") {
			if (!que.empty()) {
				cout << que.front() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (str == "back") {
			if (!que.empty()) {
				cout << que.back() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
	


}