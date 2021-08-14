#include <iostream>
#define mod 1000000000
#define ll long long
using namespace std;
int n;
ll dp[101][10]; // dp[i][j] i�ڸ� ���ڰ� j�� ���� ����� ��� �� �� ����
int main() {

	cin >> n;
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1; // 1 �ڸ����� 1�������� �ʱ�ȭ
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1] % mod;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1] % mod;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i] % mod;
	}
	cout << ans << endl;


}