#include <iostream>
#include <string>
using namespace std;

int main() {

	string a;
	cin >> a;
	int count[10] = { 0, };
	int tmp;
	for (int i = 0; i < a.length(); i++) {
		tmp = a[i]-'0';
		count[tmp]++;
	}
	for (int i = 9; i >= 0; i--) {
		if (i == 0) {
			if (count[i] != 0) {
				for (int j = 0; j < count[i]; j++) {
					printf("%d", i);
				}
			}
			else {
				break;
			}
		}
		else {
			if (count[i] != 0) {
				for (int j = 0; j < count[i]; j++) {
					printf("%d", i);
				}
			}
		}
		
	}


}