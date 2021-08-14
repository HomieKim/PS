#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int room = 0;
	int roomInNumber = 1;
	int cnt= 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			room+=1;
		}
		if (roomInNumber < i) {
			room++;
			int num = 6 * cnt;
			roomInNumber += num;
			cnt++;
		}
	}

	cout << room << endl;

}