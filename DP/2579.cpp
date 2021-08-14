#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[302] = { 0, };
int dp[302];		// n번째 계단까지 올라갔을 때의 최대값

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	// 초기값 세팅, dp[4] 부터는 연속3개 못가는 조건을 고려
	dp[1] = map[1];
	dp[2] = map[1] + map[2];
	int a = map[1] + map[3];
	int b = map[2] + map[3];
	dp[3] = max(a,b);

	for (int i = 4; i <= n; i++) {
		int tmp1 = dp[i - 2] + map[i];
		int tmp2 = dp[i - 3] + map[i - 1] + map[i];
		dp[i] = max(tmp1, tmp2);
	}

	cout << dp[n] << endl;


}