#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1002][1002];
int vis[1002][1002][2];
int dis[1002][1002];
queue<pair<pair<int, int>, int>> Q;


int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	Q.push({ { 0, 0 },0 });
	vis[0][0][0] = 1; // 벽 뚫을 수 있고, 0,0 부터 시작함 0 -> 벽 뚫을 수 있다, 1 -> 벽 이미 뚫었다.
	

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		
		if (cur.first.first == n - 1 && cur.first.second == m - 1) {
			cout << dis[cur.first.first][cur.first.second]+1 << endl; // 좌표가 n,m 까지 온건 끝났다는 의미
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.first.first + dx[i];
			int ny = cur.first.second + dy[i];
			int brk = cur.second;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 1 && brk == 1) continue; // map이 벽이고 부술기회가 없다? 진행 못하지

			if (brk == 0) {	// 벽 부술 기회 있다.
				if (map[nx][ny] == 0 && vis[nx][ny][brk] != 1) {	// 이동하려는 칸이 빈칸(0)이고 아직 방문하지 않았을 때
					vis[nx][ny][brk] = 1;	// 방문 처리 하고
					dis[nx][ny] = dis[cur.first.first][cur.first.second] + 1;
					Q.push({ {nx,ny}, brk }); // 큐에 넣어줌
					
				}
				else if (map[nx][ny] == 1) {
					vis[nx][ny][brk + 1] = 1; // 벽을 뚫을 vis 배열에 방문처리
					dis[nx][ny] = dis[cur.first.first][cur.first.second] + 1;
					Q.push({ {nx,ny},brk + 1 });
					
				}
			}
			else if (brk == 1) {	// 벽 부술 기회 없다.
				if (map[nx][ny] == 0 && vis[nx][ny][brk] != 1) {
					vis[nx][ny][brk] = 1;	// 방문 처리 하고
					dis[nx][ny] = dis[cur.first.first][cur.first.second] + 1;
					Q.push({ {nx,ny}, brk }); // 큐에 넣어줌
					
				}

			}
			
			

		}
	}


	cout << -1 << endl;


}