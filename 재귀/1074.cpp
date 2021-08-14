#include <iostream>
#include <cmath>
using namespace std;

int func(int n, int r, int c) {
	if (n == 0) return 0;
	int half = pow(2, n - 1);

	// 1,2,3,4 사분면 나눠서 재귀함수 호출
	if (r < half && c < half) return func(n - 1, r, c); // 1사분면
	if (r < half && c >= half) return half * half + func(n - 1, r, c - half);//2사분면
	if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);//3사분면
	return 3 * half * half + func(n - 1, r - half, c - half);	//4사분면
}

int main(void) {
	
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}