#include <iostream>
#include <string>

using namespace std;

int main() {

	string dial;
	cin >> dial;
	int time = 0;
	int sum;
	for (int i = 0; i < dial.length(); i++) {
		if (dial[i] == 'S') {
			time += 8;
		}
		else if (dial[i] == 'V') {
			time += 9;
		}
		else if (dial[i] == 'Y' || dial[i] == 'Z') {
			time += 10;
		}
		else {
			sum = (dial[i] - 65) / 3;
			time += 3 + sum;
		}
		
	}
	cout << time << endl;
	return 0;
}