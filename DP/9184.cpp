#include <iostream>

using namespace std;
int a, b, c, rst;
int dp[101][101][101];
int func(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	if (a > 20 || b > 20 || c > 20) {
		return func(20, 20, 20);
	}

	if (dp[a][b][c] != 0) {
		return dp[a][b][c];
	}
	else {
		if (a < b && b < c) {
			return dp[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
		}
		else {
			return dp[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
		}
	}

	
}
int main() {
	
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		rst = func(a, b, c);
		printf("w(%d, %d, %d) = %d\n", a, b, c, rst);
		
	}


}