#include <iostream>

using namespace std;

int main() {

	int num;
	cin >> num;
	int rst=0;
	while (true) {
		if (num % 5 == 0) {
			rst = num / 5;
			break;
		}
		else if ((num % 5) % 3 == 0) {
			rst += num / 5;
			rst += (num % 5) / 3;
			break;
		}
		else {
			num -= 3;
			rst ++;
		}

		if (num == 0) {
			break;
		}
		else if(num < 0) {
			rst = -1;
			break;
		}
	}
	

	cout << rst;
	
	
}