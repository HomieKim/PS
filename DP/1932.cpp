#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501];
int map[501][501];
int n;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> map[i][j];
		}
	}

	dp[0][0] = map[0][0];
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[i + 1][j] == 0) {
				dp[i + 1][j] = dp[i][j] + map[i + 1][j];
			}
			else {
				int tmp = dp[i][j] + map[i + 1][j];
				dp[i + 1][j] = max(dp[i + 1][j], tmp);
			}

			if (dp[i + 1][j + 1] == 0) {
				dp[i + 1][j+1] = dp[i][j] + map[i + 1][j+1];
			}
			else {
				int tmp = dp[i][j] + map[i + 1][j + 1];
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], tmp);
			}

		}
	}

	int rst = -1;
	for (int i = 0; i < n; i++) {
		rst = max(dp[n - 1][i], rst);
	}
	cout << rst << endl;
}