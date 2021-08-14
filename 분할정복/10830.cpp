#include <iostream>
#define ll long long
#define P 1000
using namespace std;
int n;
ll b;
ll matrix[6][6];
ll rst[6][6];

void power(ll a[6][6], ll b[6][6]) {	// a 제곱해서 에 넣음
	ll tmp[6][6] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
				tmp[i][j] %= P;
			}
			
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}


int main() {
	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			
		}
	}
	for (int i = 0; i < n; i++) {
		rst[i][i] = 1;
	}

	while (b > 0) {
		if (b % 2 != 0) {
			power(rst, matrix);
		}
		power(matrix, matrix);
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << rst[i][j] << " ";
		}
		cout << endl;
	}

}