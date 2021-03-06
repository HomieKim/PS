#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001]; // dp[N]은 n개를 구매할 때의 최댓값
int n;
int arr[1001];
int main() {
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i-j] + arr[j]);
		}
	}

	cout << dp[n] << endl;


}