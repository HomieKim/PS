#include <iostream>
#define ll long long
#define mod 1000000000
using namespace std;

ll dp[202][202];
int n, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int m = 0; m <= j; m++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][m]) % mod;
			}
		}
	}

	cout << dp[k][n] << endl;


}