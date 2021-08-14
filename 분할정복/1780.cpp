#include <iostream>

using namespace std;

int arr[2188][2188];
int oneCnt = 0, zeroCnt = 0, minusCnt = 0;
void func(int x, int y, int n) {
	int one = 0;
	int zero = 0;
	int minus = 0;

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y+n; j++) {
			if (arr[i][j] == 1) {
				one++;
			}
			else if (arr[i][j] == 0) {
				zero++;
			}
			else if (arr[i][j] == -1) {
				minus++;
			}
		}
	}
	if (one == 0 && minus == 0 && zero == n * n) {
		zeroCnt++;
		return;
	}
	else if (one == 0 && minus == n * n && zero == 0) {
		minusCnt++;
		return;
	}
	else if (one == n * n && minus == 0 && zero == 0) {
		oneCnt++;
		return;
	}

	int third = n / 3;
	int third_2 = third * 2;
	func(x, y, third);
	func(x, y+third, third);
	func(x, y+third_2, third);
	func(x+third, y, third);
	func(x+third_2, y, third);
	func(x+third, y+third, third);
	func(x+third, y+third_2, third);
	func(x+third_2, y+third, third);
	func(x+third_2, y+third_2, third);
	
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	func(0, 0, n);

	cout << minusCnt << '\n' << zeroCnt << '\n' << oneCnt << endl;

}