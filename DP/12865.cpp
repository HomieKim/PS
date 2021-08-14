#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][100001];	// i번째 까지 검사했을 경우, 무게가 j일때 v의 최댓값
vector<pair<int,int>> item;	//first 는 무게, second 는 밸류 
int n, k;
int main() {
	cin >> n >> k;
	int a, b;
	item.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		item.push_back({ a,b });
	}

	for (int i = 1; i <= n; i++) {
		int weight = item[i].first; int val = item[i].second;
		for (int j = 0; j <= k; j++) {
			if (weight > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + val);
			}
		}
	}

	
	cout << dp[n][k] << endl;

}