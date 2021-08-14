#include <iostream>
#include <vector>

using namespace std;

int n, m;

int list[9] = { 0, };
bool visit[9] = { 0, };


void func(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << list[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = num; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			list[cnt] = i;
			func(i+1,cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;

	func(1,0);
}