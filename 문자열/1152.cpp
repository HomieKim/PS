#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	getline(cin, str);
	int len = str.length();
	int cnt = 0;
	int cnt2 = 0;
	if (str[0] == ' ') {
		cnt2++;
	}
	if (str[len - 1] == ' ') {
		cnt2++;
	}
	for (int i = 0; i < len; i++) {
	
		if (str.at(i) == ' ') {
			cnt++;
		}
	}
	cout << cnt+1 -cnt2<< endl;

	return 0;
}