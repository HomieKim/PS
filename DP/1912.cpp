#include <iostream>
#include <algorithm>
#define endl '\n'
#define ll long long

using namespace std;

int n;

ll arr[1000001]; 
ll dp[1000001]; // ī���� �˰��� ��� : ���̰� n�� ������ �� �� �ִ밪
/*
���ӵ� ������ ���̱� ������ 
dp[n] ���� n��° ���� �ִ� ���� ���س����� �����ϴ� ��찡 �ΰ��� �� �ȴ�
n-1 ��° �� �� �����ϰ� n��° �Ǵ� n-1��° ���� �������� �ʰ� n��° ���� �����ϴ� ���
*/

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		
	}

	dp[0] =arr[0];
	ll rst = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1]+arr[i], arr[i]);
		rst = max(rst, dp[i]);
	}
	cout << rst << endl;



}