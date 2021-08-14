#include <iostream>
#include <queue>

using namespace std;

int miro[101][101];
int vis[101][101] = { 0, }; // �湮 �ȵǸ� 0
int n, m;
// �����¿�
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
	// ���� 0,0�� ť�� �ְ� �湮ó�� �Ѵ� �̶� �̷� ���� �Ÿ� �˱����� �湮ó���� 1 �ִ°� �ƴ϶� ++1�� ���� ������ �Ÿ� �� �� ���� ��?
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