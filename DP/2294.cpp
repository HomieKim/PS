#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int n, k;
int dp[10001];
int coins[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		dp[i] = MAX;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coins[i]]+1);
		}
	}
	int answer = dp[k] == MAX ? -1 : dp[k];
	cout << answer  << endl;

	
}