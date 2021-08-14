#include <iostream>
#include <queue>

using namespace std;

//bfs 풀이
//int map[26][26];
//bool vis[26][26];
//int n;
//queue<pair<int, int>> Q;
//priority_queue<int, vector<int>, greater<int>> numQ;
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 };
//
//int houseCnt = 0;
//int houseSize=0;
//
//void bfs(int i, int j) {
//	vis[i][j] = 1; // (i,j)로 BFS를 시작하기 위한 준비
//	Q.push({ i,j});
//
//	while (!Q.empty()) {
//		houseSize++;
//		pair<int, int> cur = Q.front();
//		Q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nx = cur.first + dx[i];
//			int ny = cur.second + dy[i];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 밖일 경우 넘어감
//			if (vis[nx][ny] || map[nx][ny] != 1) continue;
//			vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
//			Q.push({ nx,ny });
//		}
//	}
//	numQ.push(houseSize);
//	houseSize = 0;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n;
//	string s;
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		for (int j = 0; j < n; j++) {
//			map[i][j] = s[j]-'0';
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (map[i][j] == 1 && !vis[i][j]) {
//				houseCnt++;
//				bfs(i, j);
//			}
//		}
//	}
//
//	cout << houseCnt << '\n';
//
//	while (!numQ.empty()) {
//		int tmp = numQ.top();
//		cout << tmp << '\n';
//		numQ.pop();
//	}
//	
//
//} // bfs풀이

int n;
int map[26][26];
bool vis[26][26];
int houseCnt = 0;
int houseSize = 0;
priority_queue<int, vector<int>, greater<int>> numQ;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(int i, int j) {
	houseSize++;
	vis[i][j] = true;
	int k;
	for (k = 0; k < 4; k++) {
		int x = i + dx[k];
		int y = j + dy[k];

		if (x < 0 || x >= n || y < 0 || y >= n) continue;
		if (vis[x][y] || map[x][y] != 1) continue;
		dfs(x, y);
	}
	

}

int main() {
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < n;j++){
			map[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !vis[i][j]) {
				houseCnt++;
				dfs(i, j);
				numQ.push(houseSize);
				houseSize = 0;
			}
		}
	}

	cout << houseCnt << '\n';
	
	while (!numQ.empty()) {
		int tmp = numQ.top();
		cout << tmp << '\n';
		numQ.pop();
	}

}