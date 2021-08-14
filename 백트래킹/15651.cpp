#include <iostream>

using namespace std;
int n, m;
int visit[8];
int list[8];

void func(int num,int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << list[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			//visit[i] = true;
			list[cnt] = i;
			func(i,cnt+1);
			visit[i] = false;
		}
	}
}
int main() {

	cin >> n >> m;
	func(1, 0);
}