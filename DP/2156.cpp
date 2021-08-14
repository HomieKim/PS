#include <iostream>
#include <algorithm>

using namespace std;

int n;
int glass[10002];
int dp[10002]; // n번째 잔까지 왔을 때 최대값을 저장
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> glass[i];
	}

	// 초기값 셋팅
	dp[1] = glass[1];	
	dp[2] = glass[1] + glass[2];
	// 고려해야하는 경우의 수 n번째 잔을 마시지 않을 때 (dp[n-1), n번째 잔을 마실 때
	// n번째 잔을 마셨을 경우 oxo, xoo - > 이 두가지 고려해주면됨, xxo는 최대값 무조건 아니니까
	for (int i = 3; i <= n; i++) {
		int a = dp[i - 3] + glass[i - 1] + glass[i]; // xoo
		int b = dp[i - 2] + glass[i];	// oxo
		dp[i] = max(a, b);
		dp[i] = max(dp[i - 1], dp[i]);
	}


	cout << dp[n] << endl;
}