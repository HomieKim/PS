#include <iostream>
#include <cstring>
using namespace std;
int dp[32][32];
int main() {
	int t, n, m;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			dp[1][i] = i;
		}

		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j <= m; j++)
			{
				for (int k = j; k >= i; k--)
				{
					dp[i][j] +=  + dp[i - 1][k - 1];
				}
			}
		}

		cout << dp[n][m] << '\n';
		memset(dp, 0, sizeof(dp));
	}
	

}