#include <iostream>
#define P 1000000007
#define ll long long 
using namespace std;

/* 풀이 : nCr 은 n!/(r!(n-r)!) 이므로 A를 n! B를 (r!(n-r)!)이라 할 때 A/B%P 를 구하는 문제
		이때 페르마의 소정리를 사용

		페르마의 소정리	: m 이 소수 이로 a와 m이 서로소 일 때 a^m-1 mod m 은 1이됨 이때 a^m-1 = a * a^m-2 mod m 이 1 이 성립하므로 a^m-2 가 역원이 된다

		공식 대입하면 A * B^P-2 % P 하면 구하는 값이다.

		거듭제곱 공식 : m^n 일 때 n이 짝수면 m^(n/2) * m^(n/2)
									홀수면 m^((n-1)/2) * m((n-1)/2) * m
*/

ll fac(int n) {
	ll res=1;
	for (ll i = 2; i <= n; i++) {
		res *= i;
		res %= P;
	}
	return res;
}

ll power(ll value, ll p) {
	ll rst = 1;

	while (p > 0) {
		if (p % 2 != 0) {
			rst *= value;
			rst %= P;

		}
		value *= value;
		value %= P;
		p /= 2;
	}

	return rst;
}
int main() {
	ll n, k;
	cin >> n >> k;

	ll A = fac(n);
	ll B = (fac(k) * fac(n - k));
	ll C = power(B, P - 2)% P;

	ll rst = (A * C)%P;
	cout << rst << endl;

} 