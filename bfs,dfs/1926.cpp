#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int board[501][501];
bool vis[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int pictureCnt = 0;
int pictureSize = 0;
queue<pair<int, int>> Q;
int mx = 0;

void bfs(int x, int y) {

	vis[x][y] = 1; // (i,j)로 BFS를 시작하기 위한 준비
    Q.push({x,y});
	while (!Q.empty()) {
		pictureSize++;
		pair<int, int> cur = Q.front();
		Q.pop();
		
		
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
			Q.push({ nx,ny });
		}
	}
	mx = max(mx, pictureSize);
	pictureSize = 0;
}
int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || board[i][j] == 0) continue;
			pictureCnt++;
			bfs(i,j);
		}
	}

	cout << pictureCnt << '\n' << mx << '\n';
}