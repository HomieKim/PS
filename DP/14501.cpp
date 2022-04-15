#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct {
	int time;
	int price;
}typedef tb;

// N: 일수 , T: 소요 기간, P: 금액
int N, T, P;
vector<tb> table;
int dp[1500002];

int solve() {
	for (int i = 1; i <= N; i++) {
		dp[i + table[i].time] = max(dp[i + table[i].time], dp[i] + table[i].price);
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}
	return dp[N + 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	tb tmp;
	table.push_back(tmp);
	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		tmp.time = T;
		tmp.price = P;
		table.push_back(tmp);
	}

	int result = solve();

	cout << result;

}