#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s1;
string s2;
int dp[1002][1002];
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;

    for (int i = 1; i <= s1.size(); i++) {
        for (int j =1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<char> LCS_vec;
    int col = s2.size();
    int row = s1.size();
    while (true) {
        if (dp[row][col] == 0) break;
        int now_length = dp[row][col];
        if (dp[row - 1][col] == now_length - 1 && dp[row][col - 1] == now_length - 1) {
            LCS_vec.push_back(s2[col-1]);
            row--;
            col--;
        }
        else {
            if (dp[row - 1][col] == now_length) {
                row--;
            }
            else {
                col--;
            }
        }
        
    }

    cout << dp[s1.size()][s2.size()] << '\n';
    if (!LCS_vec.empty()) {
        for (int i = LCS_vec.size() - 1; i >= 0; i--) {
            cout << LCS_vec[i];
        }
    }
   

    
}
