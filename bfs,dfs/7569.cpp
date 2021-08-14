#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int box[101][101][101];
int vis[101][101][101];
queue<pair<pair<int, int>, int>> Q;

int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,0,0,-1,1 };
int dz[] = { 0,0,-1,1,0,0 };

int m, n, h;
int main() {
	cin >> m >> n >> h;
	int cnt = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					Q.push(make_pair(make_pair(i, j), k));
				}

				if (box[i][j][k] == 0) {
					cnt++;
					vis[i][j][k] = -1;
				}
			}
		}
	}

	if (cnt == 0) {
		cout << 0 << endl;
		exit(0);
	}
	while (!Q.empty()) {
		int queSize = Q.size();
		while (queSize--) {
			pair<pair<int, int>, int> cur = Q.front();
			Q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = cur.first.second + dx[i];
				int ny = cur.first.first + dy[i];
				int nz = cur.second + dz[i];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
				if (vis[ny][nx][nz] >= 0) continue;
				vis[ny][nx][nz] = vis[cur.first.first][cur.first.second][cur.second] + 1;
				Q.push(make_pair(make_pair(ny, nx), nz));
			}
		}
		
	}
	int mx = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j][k] == -1) {
					cout << -1 << endl;
					return 0;
				}

				mx = max(mx, vis[i][j][k]);
			
			}
		}
	}

	cout << mx << endl;
}