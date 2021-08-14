#include <iostream>
#include <queue>

using namespace std;

int map[51][51];
bool vis[51][51];
queue<pair<int, int>> Q;

int cnt = 0;
int t ,n, m, k;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void bfs(int i, int j) {
	vis[i][j] = true;
	Q.push({ i,j });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || map[nx][ny] != 1) continue; // 이미 방문한 칸이거나 배추가있는 칸이 아닐 경우
			vis[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}
void func(int n, int m, int k) {
	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		map[x][y] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && !vis[i][j]) {
				cnt++;
				bfs(i, j);
			}
			
		}
	}

	cout << cnt << endl;
	cnt = 0;
}
void init(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = 0;
		}
	}
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> k;
		func(n,m,k);
		init(n, m);
	}

}