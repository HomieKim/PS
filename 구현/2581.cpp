#include <iostream>

using namespace std;

bool isSosu(int num) {
	if (num == 1) {
		return false;
	}
	int flag = 0;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	int a, b;
	cin >> a >> b;
	int min = b;
	int sum = 0;
	for (int i = a; i <= b; i++) {
		if (isSosu(i)) {
			sum += i;
			if (min > i) {
				min = i;
			}
		}
	}

	if (sum == 0) {
		cout << -1 << endl;
	}
	else {
		cout << sum << endl;
		cout << min << endl;
	}
	

}