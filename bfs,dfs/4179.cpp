#include <iostream>
#include <queue>

using namespace std;
int n, m;
char miro[1002][1002];
int vis[1002][1002];
int fvis[1002][1002];
queue<pair<int, int>> Q;
queue<pair<int, int>> fQ;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	cin >> n >> m;
	string s;
	// 솔루션 :  불이 전파되는 시간을 먼저 bfs로 돌려서 구해놓고 이동하는 bfs를 그다음 돌리는데 조건에 불이 붙어있으면 continue 되게
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			miro[i][j] = s[j];
			if (miro[i][j] == 'J') {
				Q.push({ i,j });
				vis[i][j] = 0;
				fvis[i][j] = -1;
			}
			else if (miro[i][j] == 'F') {
				fQ.push({ i,j });
				fvis[i][j] = 0;
				vis[i][j] = -1;
			}
			else {
				vis[i][j] = -1;
				fvis[i][j] = -1;
			}
		}
	}

	while (!fQ.empty()) {
		pair<int, int> cur = fQ.front();
		fQ.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (miro[nx][ny] == '#' || fvis[nx][ny] >= 0) continue;
			
			fvis[nx][ny] = fvis[cur.first][cur.second] + 1;
			fQ.push({ nx,ny });
		}
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << vis[cur.first][cur.second]+1 << endl;
				return 0;
			}
			if (miro[nx][ny] == '#' || vis[nx][ny] >= 0) continue;
			if (fvis[nx][ny] != -1 && fvis[nx][ny] <= vis[cur.first][cur.second]+1)continue;

			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}