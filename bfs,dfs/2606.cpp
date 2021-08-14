#include <iostream>

using namespace std;
int n, m;
int com[101][101];
int cnt = 0;
bool vis[101];

void dfs(int start) {
	cnt++;
	vis[start] = true;

	for (int i = 1; i <= n; i++) {
		if (com[start][i] && !vis[i]) {
			vis[i] = true;
			dfs(i);
		}
	}
}
int main() {

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		com[a][b] = 1;
		com[b][a] = 1;
	}
	dfs(1);

	cout << cnt -1<< endl;


}