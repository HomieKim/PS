#include <iostream>

using namespace std;
bool visit[9] = { 0, };
int tree[9] = { 0, };
int n, m;
void func(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << tree[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			tree[cnt] = i;
			func(cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	
	cin >> n >> m;

	func(0);

}