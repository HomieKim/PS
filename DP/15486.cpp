#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N: �ϼ� , T: �ҿ� �Ⱓ, P: �ݾ�
int N, T, P;
int dp[1500010]; // dp[n] : n�Ͽ� ���� �� �ִ� �ִ� �ݾ�
vector<pair<int, int>> table;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	table.push_back({ 0,0 });
	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		table.push_back({ T,P });
	}
	table.push_back({ 0,0 });
	int curMax=0;
	for (int i = 1; i <= N+1; i++) {
		curMax = max(curMax, dp[i]);
		if (table[i].first + i > N + 1) continue;
		dp[i+table[i].first] = max(dp[i+table[i].first], curMax + table[i].second);
	}

	cout << curMax << endl;
}