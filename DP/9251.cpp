#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;
string s1, s2;
char c1[1002];
char c2[1002];
int dp[1002][1002];

/* lcs 알고리즘 : 최장 공통 부분 수열 알고리즘
솔루션 : 가장 끝에있는 문자를 기준으로 생각하고 비교
예를 들어
가장 끝문자가 같은 경우 
ABC CAB -> AB 와 CA의 LCS 에서 +1을 해주면 된다
가장 끝 문자가 다른경우?
ABCD CDBA -> ABCD CDB 와 ABC CDBA의 LCS 중 최대값을 취하면 됨
*/
int main() {
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++) {
		c1[i] = s1[i];
	}
	for (int i = 0; i < s2.size(); i++) {
		c2[i] = s2[i];
	}

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (c1[i-1] == c2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[s1.size()][s2.size()] << endl;
}