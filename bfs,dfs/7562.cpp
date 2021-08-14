#include <iostream>
#include <queue>
using namespace std;

int board[301][301];	// 거리 표시용
int vis[301][301];

queue<pair<int, int>> Q;

int m,n, a,b,c,d;

int dx[] = {-1,-2, -2, -1, 1, 2, 2, 1};
int dy[] = { 2, 1, -1, -2, -2, -1, 1,2};
void bfs() {
	Q.push({ a,b });
	vis[a][b] = 1;
	board[a][b] = 0;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		
		if (cur.first == c && cur.second == d) {
			cout <<board[cur.first][cur.second] << endl;
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] == 1) continue;
			board[nx][ny] = board[cur.first][cur.second] + 1;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });


		}
	}

}
void init() {
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			board[i][j] = 0;
			vis[i][j] = 0;
		}
	}
	Q = queue <pair<int, int>>();
}
int main() {

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> n;
		cin >> a >> b >> c >> d;	// a,b -> 시작 좌표, c,d 목적지 좌표
		bfs();
		init();
	}


}