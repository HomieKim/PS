#include <iostream>
#include <cmath>
using namespace std;

int func(int n, int r, int c) {
	if (n == 0) return 0;
	int half = pow(2, n - 1);

	// 1,2,3,4 ��и� ������ ����Լ� ȣ��
	if (r < half && c < half) return func(n - 1, r, c); // 1��и�
	if (r < half && c >= half) return half * half + func(n - 1, r, c - half);//2��и�
	if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);//3��и�
	return 3 * half * half + func(n - 1, r - half, c - half);	//4��и�
}

int main(void) {
	
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}