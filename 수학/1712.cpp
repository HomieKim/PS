#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int fix, price, sell;
	cin >> fix; cin >> price; cin >> sell;

	if (price >= sell) {
		cout << -1 << endl;
	}
	else {
		int i = 1;
		while (true) {
			if (fix / (sell - price) < i) {
				cout << i << endl;
				break;
			}
			else {
				i++;
			}
		}
	}
}