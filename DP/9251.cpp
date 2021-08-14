#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;
string s1, s2;
char c1[1002];
char c2[1002];
int dp[1002][1002];

/* lcs �˰��� : ���� ���� �κ� ���� �˰���
�ַ�� : ���� �����ִ� ���ڸ� �������� �����ϰ� ��
���� ���
���� �����ڰ� ���� ��� 
ABC CAB -> AB �� CA�� LCS ���� +1�� ���ָ� �ȴ�
���� �� ���ڰ� �ٸ����?
ABCD CDBA -> ABCD CDB �� ABC CDBA�� LCS �� �ִ밪�� ���ϸ� ��
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