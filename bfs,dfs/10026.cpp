#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int vis[101][101];
int n;
queue<pair<int, int>> que;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
// R: 1, G: 2, B: 3
int RG = 0;
int notRG = 0;
void bfs(int a, int b) {
	int nowColor = map[a][b];
	que.push({ a,b });
	vis[a][b] = 1;

	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] == 1 || map[nx][ny] != nowColor) continue;
			vis[nx][ny] = 1;
			que.push({ nx,ny });

		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'R') {
				map[i][j] = 1;
			}
			else if (s[j] == 'G') {
				map[i][j] = 2;
			}
			else {
				map[i][j] = 3;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				notRG++;
				bfs(i,j);
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 2) map[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				RG++;
				bfs(i, j);
			}
		}
	}
	cout << notRG << " "<< RG<<endl;

}