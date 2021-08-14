#include <iostream>
#include <queue>
#define MAX 102

using namespace std;

int m, n, k;
int square[MAX][MAX];
int vis[MAX][MAX];

queue<pair<int, int>> que;
priority_queue<int,vector<int>,greater<int>> sizeque;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int cnt = 0;
int sqSize = 0;

void bfs(int y, int x) {
	que.push({ y,x });
	vis[y][x] = 1;
	while (!que.empty()) {
		sqSize++;
		auto cur = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
			if (vis[nx][ny] || square[nx][ny] != 0) continue;
			vis[nx][ny] = 1; 
			que.push({ nx,ny });
		}
	}
	sizeque.push(sqSize);
	sqSize = 0;
}
int main() {
	cin >> m >> n >> k;
	int x1, y1, x2, y2;
	for(int i = 0; i <k;i++){
		cin >> x1 >> y1 >> x2 >> y2;
		int X = x2 - x1;
		int Y = y2 - y1;
		for (int j = 0; j < X; j++) {
			for (int k = 0; k < Y; k++) {
				square[j+x1][k+y1] = 1;
				
			}
		}

	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << square[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 1 || square[i][j] == 1) continue;
			cnt++;
			bfs(i, j);
		}
	}

	cout << cnt << endl;
	while (!sizeque.empty()) {
		cout << sizeque.top() << " ";
		sizeque.pop();
	}
	
	


}