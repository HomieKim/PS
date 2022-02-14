#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2, s3;
int dp[102][102][102];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2 >> s3;

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            for (int m = 1; m <= s3.size(); m++) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[m - 1]) {
                    dp[i][j][m] = dp[i - 1][j - 1][m - 1] + 1;
                }
                else {
                    dp[i][j][m] = max(max(dp[i - 1][j][m], dp[i][j - 1][m]), dp[i][j][m - 1]);
                }
            }
        }
    }
    cout << dp[s1.size()][s2.size()][s3.size()] << '\n';
}