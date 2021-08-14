#include <iostream>
#define ll long long
#define P 1000000007

using namespace std;
ll n;

ll mat[2][2] = { {1,1},{1,0} };
ll rst[2][2] = { {1,0},{0,1} };

void power(ll a[][2], ll b[][2]) {	
	ll tmp[2][2] = { 0, };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
			tmp[i][j] %= P;

		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}
int main() {
	cin >> n;

	while (n> 0) {
		if (n % 2 != 0) {
			power(rst, mat);
		}
		power(mat, mat);
		n /= 2;
	}

	cout << rst[0][1] << endl;


}