#include <iostream>

using namespace std;

int main() {
	
	int x1, y1;
	int x2, y2;
	int x3, y3;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	int rstX, rstY;
	if (x1 == x2) {
		rstX = x3;
	}
	else if(x1 == x3) {
		rstX = x2;
	}
	else {
		rstX = x1;
	}

	if (y1 == y2) {
		rstY = y3;
	}
	else if (y1 == y3) {
		rstY = y2;
	}
	else {
		rstY = y1;
	}

	cout << rstX << " " << rstY << endl;

}