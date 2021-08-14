#include <iostream>
#include <algorithm>

using namespace std;

int n;
int glass[10002];
int dp[10002]; // n��° �ܱ��� ���� �� �ִ밪�� ����
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> glass[i];
	}

	// �ʱⰪ ����
	dp[1] = glass[1];	
	dp[2] = glass[1] + glass[2];
	// ����ؾ��ϴ� ����� �� n��° ���� ������ ���� �� (dp[n-1), n��° ���� ���� ��
	// n��° ���� ������ ��� oxo, xoo - > �� �ΰ��� ������ָ��, xxo�� �ִ밪 ������ �ƴϴϱ�
	for (int i = 3; i <= n; i++) {
		int a = dp[i - 3] + glass[i - 1] + glass[i]; // xoo
		int b = dp[i - 2] + glass[i];	// oxo
		dp[i] = max(a, b);
		dp[i] = max(dp[i - 1], dp[i]);
	}


	cout << dp[n] << endl;
}