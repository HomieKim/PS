#include <iostream>
#include <vector>

using namespace std; 
int arr[65][65];
vector<int> rst[65];
void func(int x, int y, int n) {
	int oneCnt = 0;
	int zeroCnt = 0;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] == 1) {
				oneCnt++;
			}
			else if (arr[i][j] == 0) {
				zeroCnt++;
			}
		}
	}

	if (zeroCnt == 0 && oneCnt == n * n) {
		cout << 1;
		return;
	}
	else if (zeroCnt == n * n && oneCnt == 0) {
		cout << 0;
		return;
	}
	int half = n / 2;
	cout << '(';
	func(x, y, half);
	func(x, y + half, half);
	func(x + half, y, half);
	func(x + half, y + half, half);
	cout << ')';
}
int main() {
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	func(0, 0, n);
}