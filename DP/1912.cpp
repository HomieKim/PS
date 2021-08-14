#include <iostream>
#include <algorithm>
#define endl '\n'
#define ll long long

using namespace std;

int n;

ll arr[1000001]; 
ll dp[1000001]; // 카데인 알고리즘 사용 : 길이가 n인 수열의 합 중 최대값
/*
연속된 수열의 합이기 때문에 
dp[n] 에서 n번째 까지 최대 합을 구해놓으면 선택하는 경우가 두가지 가 된다
n-1 번째 수 를 선택하고 n번째 또는 n-1번째 수를 선택하지 않고 n번째 수를 선택하는 경우
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