#include <iostream>
#include <queue>

using namespace std;
int n;
priority_queue<int,vector<int>,greater<int>> que;
int main() {
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		que.push(a);
	}
	int minTime = 0;
	int stackTime = 0;
	while (true) {
		if (que.empty()) {
			cout << stackTime << endl;
			break;
		}
		minTime += que.top();
		stackTime += minTime;
		que.pop();
	}
}