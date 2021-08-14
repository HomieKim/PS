#include <iostream>
#define P 15746
#define MAX 1000002

long long dp[MAX];

using namespace std;
long long fibo(long long n) {
	if (n <= 2) {
		return dp[n];
	}

	if (dp[n] != 0) {
		return dp[n] % P;
	}
	else {
		return dp[n] = (fibo(n - 1)%P) + (fibo(n - 2) % P);
	}


}
int main() {
	long long n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	long long rst = fibo(n)%P;
	cout << rst << endl;

}