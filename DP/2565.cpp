#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
vector<pair<int, int>> line;
int n;
int dp[501];
int arr[501];

int main() {

	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		line.push_back({ a,b });
	}
	sort(line.begin(), line.end());

	for (int i = 0; i < n; i++) {
		arr[i] = line[i].second;
	}

	dp[0] = 1;
	int maxAns = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i; j > 0; j--) {
			if (arr[j - 1] < arr[i]) {
				dp[i] = max(dp[i], dp[j - 1]+1);
			}
		}
		maxAns = max(maxAns, dp[i]);
	}

	cout << n - maxAns << '\n';
}