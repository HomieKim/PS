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
	int n;
	cin >> n;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (isSosu(num)) {
			cnt++;
		}
	}

	cout << cnt << endl;


}