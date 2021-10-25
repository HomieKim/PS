#include <iostream>
#define mod 10007

using namespace std;
int dp[1001][11]; // dp[i][j]�� i�ڸ� ���� �� ���ڸ��� j�� �� ������ ��
int main() {
	int n;
	int rst = 0;
	cin >> n;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1; // 1�ڸ� ���ڴ� ����� ���� ������ �ϳ�
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