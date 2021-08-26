#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int map[102][102];
int wet[102][102];
int vis[102][102];
int maxCnt = 1;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y) {
	vis[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (vis[nx][ny] != 0 || wet[nx][ny] == 1) continue;
		dfs(nx, ny);
	}
}

void setWet(int height) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] < height) {
				wet[i][j] = 1;
			}
		}
	}
}

int main() {
	cin >> n;
	int heightMax = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (heightMax < map[i][j]) {
				heightMax = map[i][j];
			}
		}
	}
	int cnt;
	for (int k = 1; k <= heightMax; k++) {
		memset(wet, 0, sizeof(wet));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		setWet(k);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j] == 0 && wet[i][j] != 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		maxCnt = max(maxCnt, cnt);
	}

	cout << maxCnt << endl;

}