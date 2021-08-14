#include <iostream>
#include <algorithm>
#define MAX 1000001

using namespace std;

int n;
int dp[1000001];


int main() {
	cin >> n;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	for (int i = 4; i <= n; i++) {
		int tmp1 = MAX;
		int tmp2 = MAX;
		int tmp3 = MAX;
		if (i % 2 == 0) {
			tmp1 = dp[i / 2]+1;
		}
		if (i % 3 == 0) {
			tmp2 = dp[i / 3]+1;
		}
		tmp3 = dp[i - 1]+1;

		dp[i] = min(min(tmp1, tmp2), tmp3);

	}
	cout << dp[n] << endl;

}