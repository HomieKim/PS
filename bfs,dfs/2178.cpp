#include <iostream>
#include <queue>

using namespace std;

int miro[101][101];
int vis[101][101] = { 0, }; // 방문 안되면 0
int n, m;
// 상하좌우
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int main() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >>s;
		for (int j = 0; j < m; j++) {
			miro[i][j] = s[j]-'0';
		}

	}
	
	queue<pair<int, int>> Q;
	// 최초 0,0을 큐에 넣고 방문처리 한다 이때 미로 와의 거리 알기위해 방문처리시 1 넣는게 아니라 ++1한 값을 넣으면 거리 알 수 있을 듯?
	Q.push({ 0,0 });
	
	vis[0][0] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] != 0 || miro[nx][ny] != 1) continue;
		
			vis[nx][ny] = vis[cur.first][cur.second]+1;
			Q.push({ nx,ny });

		}
	}

	cout << vis[n-1][m-1] << '\n';
}