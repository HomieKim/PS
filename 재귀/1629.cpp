#include <iostream>

using namespace std;

long long func(long long a, long long n, long long c) {
	long long rst;
	
	if (n == 1) { // ���� ���� n�� ������ a�� 1���� a�̰� ���� ũ�� ���� �� ������ %c �ؼ� �ѱ�
		return a %c;
	}

	rst = func(a, n / 2, c);
	rst = rst * rst % c; // ���⼭ ���� %c ����
	if (n % 2 == 0) {
		return rst;	// ¦���� ��� ���ؼ� ���� %c �������ϱ� �� ���� �ϸ��
	}
	else {
		return rst * a % c;	// Ȧ���� a�ѹ� �� ��������ϰ� %c�� �ѹ� ���������
							// ���� : a^n %c = X ��� �� �� �� -> a^2n %c = X*X ��� ����
	}
}

	
int main() {

	long long a, n, c;
	cin >> a >> n >> c;
	cout << func(a, n, c) << endl;
}