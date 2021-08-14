#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[9][9];
int n, m;
int ans = 1000;
int zeroCnt;
vector<pair<pair<int,int>,int>> cctv;
/* 가능한 경우 
	1번 카메라 - 4가지 
	2번 카메라 - 2가지
	3번 카메라 - 4가지
	4번 카메라 - 4가지
	5번 카메라 - 1가지
*/
void copymap(int x[9][9], int y[9][9]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			x[i][j] = y[i][j];
		}
	}
}
void setMap(int i, int x, int y) {
	
	if (i == 0) {	// 상
		int nx = x - 1;
		while (nx >= 0) {
			if (map[nx][y] == 0) {
				map[nx][y] = 9;
			}

			if (map[nx][y] == 6) {
				return;
			}
			
			nx--;
		}
	}
	else if (i == 2) {	//하
		int nx = x + 1;
		while (nx <= n-1) {
			if (map[nx][y] == 0) {
				map[nx][y] = 9;
			}

			if (map[nx][y] == 6) {
				return;
			}
			nx++;
		}
	}
	else if (i == 3) {	// 좌
		int ny = y - 1;
		while (ny >= 0) {
			if (map[x][ny] == 0) {
				map[x][ny] = 9;
			}

			if (map[x][ny] == 6) {
				return;
			}
			ny--;
		}
	}
	else if (i == 1) {	// 우
		int ny = y + 1;
		while (ny <= m-1 ) {

			if (map[x][ny] == 0) {
				map[x][ny] = 9;
			}

			if (map[x][ny] == 6) {
				return;
			}
			ny++;
		}
	}
}

int zero() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cnt += 1;
			}
		}
	}
	/*cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/
	return cnt;
}
void dfs(int n) {
	if (n == cctv.size()) {
		zeroCnt = zero();// 사각지대 횟수 세기
		ans = min(zeroCnt, ans);
		return;
	}
	int tmpMap[9][9];
	auto tmp = cctv[n];

	int x = tmp.first.first;
	int y = tmp.first.second;

	switch (tmp.second)
	{
	case 1:
		for (int i = 0; i < 4; i++) {
			copymap(tmpMap, map);
			setMap(i, x, y);
			dfs(n + 1);
			copymap(map, tmpMap);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {	// 좌우23, 상하01 
			copymap(tmpMap, map);
			setMap(i, x, y);
			setMap(i + 2, x, y);
			dfs(n + 1);
			copymap(map, tmpMap);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			copymap(tmpMap, map);
			setMap(i, x, y);
			setMap((i + 1) % 4, x, y);
			dfs(n + 1);
			copymap(map, tmpMap);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			copymap(tmpMap, map);
			setMap(i, x, y);
			setMap((i + 1) % 4, x, y);
			setMap((i + 2) % 4, x, y);
			dfs(n + 1);
			copymap(map, tmpMap);
		}
		break;
	case 5:
		copymap(tmpMap, map);
		for (int i = 0; i < 4; i++) {
			setMap(i, x, y);
		}
		dfs(n + 1);
		copymap(map, tmpMap);
		break;
	}

	
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) {
				cctv.push_back({ {i,j},map[i][j] });
			}
		}
	}

	dfs(0);

	cout << ans << endl;

}