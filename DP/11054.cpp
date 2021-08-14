#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1003];
int dp[1003]; 
int reDp[1003];
int reArr[1003];

int rst[1003];

int func(int maxAns, int i, int* dp, int* arr) {
	int tmp = 0;
	for (int j = i; j > 0; j--) {
		if (arr[j - 1] < arr[i]) {
			tmp = max(tmp, dp[j - 1]);
		}

		if (tmp == 0) {
			dp[i] = 1;
		}
		else {
			dp[i] = tmp + 1;
		}
		maxAns = max(maxAns, dp[i]);
	}

	return maxAns;
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		reArr[n -1-i] = arr[i];
	}
	dp[0] = 1;
	reDp[0] = 1;
	int maxAns = 1;
	int reAns = 1;

	for (int i = 1; i < n; i++) {
		
		maxAns = func(maxAns,i, dp, arr);
		reAns = func(reAns, i, reDp, reArr);
		
	}

	/*for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << reArr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << reDp[i] << " ";
	}
	cout << endl;*/

	rst[0] = maxAns;
	rst[n-1] = reAns;
	int maxResult = 1;
	for (int i = 1; i < n-1; i++) {
		rst[i] = dp[i] + reDp[n - i - 1] - 1;
		maxResult = max(rst[i], maxResult);
	}
	maxResult = max(max(maxAns,reAns), maxResult);
	cout << maxResult << '\n';

}