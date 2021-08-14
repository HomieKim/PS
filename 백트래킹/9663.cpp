#include <iostream>
using namespace std;
int n;
int col[16];
bool isAble(int num) {
	for (int i = 0; i < num; i++) {
		if (col[num] == col[i]) return false;
		if (abs(num - i) == abs(col[num] - col[i])) return false;
	}
	return true;
}
int Nqueen(int num) {
	if (num == n) {
		return 1;
	}

	int rst = 0;
	for (int i = 0; i < n; i++) {
		col[num] = i;
		if (isAble(num)) rst += Nqueen(num + 1);
	}
	return rst;
}
int main() {
	cin >> n;
	cout << Nqueen(0) << '\n';
}