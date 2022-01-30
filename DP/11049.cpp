#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
int dp[502][502];
int r, c, N;
vector<pair<int, int>> matrix;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	matrix.push_back({ 0,0 });
	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		matrix.push_back({ r,c });
	}

	for (int i = 1; i < N; i++) {
		dp[i][i + 1] = matrix[i].first * matrix[i].second * matrix[i + 1].second;
	}

	for (int m = 2; m < N; m++) {
		for (int i = 1; i <= N - m; i++) {
			int j = i + m;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (matrix[i].first * matrix[k].second * matrix[j].second));
				
			}
		}
	}

	cout << dp[1][N];

}