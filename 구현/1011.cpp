#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long int a, b;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		int distance = b - a;

		long long a = 1;
		while (true) {
			if (a * a > distance) {
				break;
			}
			a++;
		}
		a--;

		if (distance == a * a) {
			cout << 2 * a - 1<< endl;
		}
		else if (distance -(a*a) > (a * 2) / 2) {
			cout << 2 * a + 1 << endl;
		}
		else {
			cout << 2 * a << endl;
		}

	}
		
}