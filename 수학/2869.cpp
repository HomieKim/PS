#include <iostream>

using namespace std;

int main() {
	int A, B, V;
	cin >> A;
	cin >> B;
	cin >> V;
	
	int dayUp = A - B;
	int var = V - A;
	int rst;
	if (dayUp == 1) {
		rst = V - B;
	}
	else {
		if (var % dayUp == 0) {
			rst = var / dayUp + 1;
		}
		else {
			rst = var / dayUp + 2;
		}
	}
	
	
	cout << rst << endl;

}