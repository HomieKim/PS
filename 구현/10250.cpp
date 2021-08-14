#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;
	int h, w, num;
	
	for (int i = 0; i < n; i++) {
		cin >> h;
		cin >> w;
		//vector<vector<int>> hotel(w, vector<int>(h));
		cin >> num;
		int floor, ho;
		if (num % h == 0) {
			floor = h;
			ho = num / h;
		}
		else {
			floor = num % h;
			ho = num / h;
			ho += 1;
		}

		if (ho >= 10) {
			cout << floor << ho << endl;
		}
		else {
			cout << floor << 0 << ho << endl;
		}
	}

}