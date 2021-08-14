#include <iostream>
#include <vector>

using namespace std;

int board[10][10];
vector<pair<int, int>> zeroIdx;

bool rowChk(int x, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == num) return false;
	}
	return true;
}

bool colChk(int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[i][y] == num) return false;
	}
	return true;
}

bool squareChk(int x, int y, int num) {
	x = x / 3;
	y = y / 3;
	for (int i = x * 3; i < (x * 3) + 3; i++) {
		for (int j = y * 3; j < (y* 3) + 3; j++) {
			if (board[i][j] == num) return false;
		}
	}

	return true;
}


bool chk(int x, int y, int i) {
	if (rowChk(x, i) && colChk(y, i) && squareChk(x, y, i)) {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int num) {
	if (num == zeroIdx.size()) {
		
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}

	for (int i = 1; i <= 9; i++) {
		int x = zeroIdx[num].first;
		int y = zeroIdx[num].second;
		if (chk(x, y, i)) {
			board[x][y] = i;
			dfs(num + 1);
			board[x][y] = 0;
		}
	}
}


int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int tmp;
			cin >> tmp;

			board[i][j] = tmp;

			if (tmp == 0) {
				zeroIdx.push_back({ i,j });
			}
		}
	}

	dfs(0);
}