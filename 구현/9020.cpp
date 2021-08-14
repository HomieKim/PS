#include <iostream>

using namespace std;

int vec[10001];

int main() {

	int n;
	cin >> n;
	vec[0] = 0;
	vec[1] = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		for (int i = 2; i <= num; i++) {
			vec[i] = i;
		}
		for (int i = 2; i <= num; i++) {
			if (vec[i] == 0) continue;
			for (int j = i + i; j <= num; j += i) {
				vec[j] = 0;
			}
		}

		int chk = num / 2;
		int x = 0;
		if (vec[chk] != 0) {
			cout << vec[chk] << " " << vec[chk] << endl;
		}
		else {
			while (vec[chk + x] + vec[chk - x] != num) {
				x++;
			}
			cout << chk -x << " " << chk +x << endl;
		}

	}
}