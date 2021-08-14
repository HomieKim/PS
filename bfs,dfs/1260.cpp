#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
int node[1001][1001];
bool vis[1001];
queue<int> Q;
void dfs(int num) {
	vis[num] = true;
	cout << num << ' ';

	for (int i = 1; i <= n; i++) {
		if (node[num][i] && !vis[i]) {
			vis[i] = true;
			dfs(i);
		}
	}

}
void bfs(int num) {
	vis[num] = true;
	Q.push(num);
	

	while (!Q.empty()) {
		int tmp = Q.front();
		Q.pop();
		cout << tmp << ' ';
		for (int i = 1; i <= n; i++) {
			if (node[tmp][i] && !vis[i]) {
				vis[i] = true;
				Q.push(i);
			}
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a][b] = 1;
		node[b][a] = 1;
	}

	dfs(v);
	cout << '\n';
	fill(vis, vis + 1001, false);

	bfs(v);
	cout << '\n';

	
}