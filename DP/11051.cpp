#include <iostream>
#define MAX 1002
using namespace std;

int dp[MAX][MAX];
int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == 0 || i == j) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
			}
		}
	}
	cout << dp[n][k] << endl;
}