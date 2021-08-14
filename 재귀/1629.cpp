#include <iostream>

using namespace std;

long long func(long long a, long long n, long long c) {
	long long rst;
	
	if (n == 1) { // 종료 조건 n은 지수승 a의 1승은 a이고 숫자 크면 터질 수 있으니 %c 해서 넘김
		return a %c;
	}

	rst = func(a, n / 2, c);
	rst = rst * rst % c; // 여기서 제곱 %c 해줌
	if (n % 2 == 0) {
		return rst;	// 짝수의 경우 위해서 제곱 %c 해줬으니까 걍 리턴 하면됨
	}
	else {
		return rst * a % c;	// 홀수면 a한번 더 곱해줘야하고 %c도 한번 더해줘야함
							// 공식 : a^n %c = X 라는 식 일 때 -> a^2n %c = X*X 요론 느낌
	}
}

	
int main() {

	long long a, n, c;
	cin >> a >> n >> c;
	cout << func(a, n, c) << endl;
}