#include <iostream>
#include <string>

using namespace std;
int reverse(int n) {
	int num = 0;
	while (n != 0) {
		num *= 10;
		num += n % 10;
		n /= 10;
		
	}
	return num;
}
int main() {
	int n1, n2;
	cin >> n1; 
	cin >> n2;
	int rst1 = reverse(n1);
	int rst2 = reverse(n2);

	if (rst1 > rst2) {
		cout << rst1 << endl;
	}
	else {
		cout << rst2 << endl;
	}

}