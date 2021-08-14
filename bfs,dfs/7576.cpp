#include <iostream>
#include <queue>

using namespace std;

int n, m;
int box[1001][1001];
int vis[1001][1001];


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	cin >> m >> n;
	queue <pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				Q.push({ i,j });
				
			}
			if (box[i][j] == 0) {
				vis[i][j] = -1;
			}
		}
	}


	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] >= 0) continue;

			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			Q.push({ nx,ny });

		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == -1) {
				cout << -1 << endl;
				return 0;
			}
			mx = max(mx, vis[i][j]);
		}
	}
	cout << mx << endl;
}