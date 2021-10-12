#include <iostream>
#define MAX 1002
#define mod 10007

using namespace std;
int dp[MAX];
int main() {
	int n;
	dp[0] = 1;
	dp[1] = 2;
	cin >> n;

	for (int i = 2; i < n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	int i;
	cout << dp[n - 1] << '\n';
}