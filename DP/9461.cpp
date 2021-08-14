#include <iostream>

using namespace std;
long long dp[101] = { 0, };
int n, T;
long long func(int n) {
	if (n < 3) {
		return dp[n];
	}

	if (dp[n] != 0) {
		return dp[n];
	}
	else {
		return dp[n] = func(n - 3) + func(n - 2);
	}
}
int main() {
	cin >> T;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << func(n-1) << endl;
	}

}