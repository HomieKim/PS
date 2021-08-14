#include <iostream>
#define P 1000000007
#define ll long long 
using namespace std;

/* Ǯ�� : nCr �� n!/(r!(n-r)!) �̹Ƿ� A�� n! B�� (r!(n-r)!)�̶� �� �� A/B%P �� ���ϴ� ����
		�̶� �丣���� �������� ���

		�丣���� ������	: m �� �Ҽ� �̷� a�� m�� ���μ� �� �� a^m-1 mod m �� 1�̵� �̶� a^m-1 = a * a^m-2 mod m �� 1 �� �����ϹǷ� a^m-2 �� ������ �ȴ�

		���� �����ϸ� A * B^P-2 % P �ϸ� ���ϴ� ���̴�.

		�ŵ����� ���� : m^n �� �� n�� ¦���� m^(n/2) * m^(n/2)
									Ȧ���� m^((n-1)/2) * m((n-1)/2) * m
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