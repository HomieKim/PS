#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int rPlus = r1 + r2;
		int rMinus = max(r1 ,r2) - min(r1,r2);
		double d = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
		// 두점에서 만날때 
		if (d == 0.0) {
			if (rMinus == 0)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}
		else {
			if (rMinus< d && rPlus > d)
				cout << 2 << endl;
			else if (rPlus == d || rMinus == d)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}

}