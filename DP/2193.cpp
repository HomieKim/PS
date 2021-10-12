#include <iostream>
#define MAX 100


using namespace std;
long long dp[MAX];
int main() {
	int n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	cin >> n;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << '\n';
}