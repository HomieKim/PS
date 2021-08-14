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
	vis[0][0][0] = 1; // �� ���� �� �ְ�, 0,0 ���� ������ 0 -> �� ���� �� �ִ�, 1 -> �� �̹� �վ���.
	

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		
		if (cur.first.first == n - 1 && cur.first.second == m - 1) {
			cout << dis[cur.first.first][cur.first.second]+1 << endl; // ��ǥ�� n,m ���� �°� �����ٴ� �ǹ�
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.first.first + dx[i];
			int ny = cur.first.second + dy[i];
			int brk = cur.second;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 1 && brk == 1) continue; // map�� ���̰� �μ���ȸ�� ����? ���� ������

			if (brk == 0) {	// �� �μ� ��ȸ �ִ�.
				if (map[nx][ny] == 0 && vis[nx][ny][brk] != 1) {	// �̵��Ϸ��� ĭ�� ��ĭ(0)�̰� ���� �湮���� �ʾ��� ��
					vis[nx][ny][brk] = 1;	// �湮 ó�� �ϰ�
					dis[nx][ny] = dis[cur.first.first][cur.first.second] + 1;
					Q.push({ {nx,ny}, brk }); // ť�� �־���
					
				}
				else if (map[nx][ny] == 1) {
					vis[nx][ny][brk + 1] = 1; // ���� ���� vis �迭�� �湮ó��
					dis[nx][ny] = dis[cur.first.first][cur.first.second] + 1;
					Q.push({ {nx,ny},brk + 1 });
					
				}
			}
			else if (brk == 1) {	// �� �μ� ��ȸ ����.
				if (map[nx][ny] == 0 && vis[nx][ny][brk] != 1) {
					vis[nx][ny][brk] = 1;	// �湮 ó�� �ϰ�
					dis[nx][ny] = dis[cur.first.first][cur.first.second] + 1;
					Q.push({ {nx,ny}, brk }); // ť�� �־���
					
				}

			}
			
			

		}
	}


	cout << -1 << endl;


}