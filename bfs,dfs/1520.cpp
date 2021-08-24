#include <iostream>

using namespace std;

int m, n;
int map[502][502];
int dp[502][502];
int vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int dfs(int i, int j) {
	if (i == m - 1 && j == n - 1) return 1;
	if (vis[i][j]) return dp[i][j];

	vis[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if (map[nx][ny] < map[i][j]) {
				dp[i][j] += dfs(nx, ny);
			}
		}
	}

	return dp[i][j];

}
int main() {
	
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(0, 0) << endl;
	
}