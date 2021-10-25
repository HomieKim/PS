#include <iostream>
#define mod 10007

using namespace std;
int dp[1001][11]; // dp[i][j]는 i자리 숫자 중 끝자리가 j일 때 오르막 수
int main() {
	int n;
	int rst = 0;
	cin >> n;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1; // 1자리 숫자는 경우의 수가 무조건 하나
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int m = 0; m <= j; m++) {
				dp[i][j] = (dp[i][j]+dp[i-1][m]) % mod;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		rst += dp[n][i] % mod;
	}
	cout << rst % mod << endl;
}