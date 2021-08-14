#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[1002];
int dp[1002];


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	int maxAns = 1;
	for (int i = 1; i < n; i++) {
		int tmp = 0;
		for (int j = i; j > 0; j--) {
			if (arr[j - 1] < arr[i]) {
				tmp = max(tmp, dp[j - 1]);
			}

			if (tmp == 0) {
				dp[i] = 1;
			}
			else {
				dp[i] = tmp+1;
			}
		}
		maxAns = max(maxAns, dp[i]);
	}
	/*for (int i = 0; i < n; i++) {
		cout << dp[i];
	}*/

	cout << maxAns << endl;
	
}