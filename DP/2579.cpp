#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[302] = { 0, };
int dp[302];		// n��° ��ܱ��� �ö��� ���� �ִ밪

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	// �ʱⰪ ����, dp[4] ���ʹ� ����3�� ������ ������ ���
	dp[1] = map[1];
	dp[2] = map[1] + map[2];
	int a = map[1] + map[3];
	int b = map[2] + map[3];
	dp[3] = max(a,b);

	for (int i = 4; i <= n; i++) {
		int tmp1 = dp[i - 2] + map[i];
		int tmp2 = dp[i - 3] + map[i - 1] + map[i];
		dp[i] = max(tmp1, tmp2);
	}

	cout << dp[n] << endl;


}