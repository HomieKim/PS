#include <iostream>
#include <string>

using namespace std;

bool is666(string str) {
	int len = str.length();
	for (int i = 0; i <= len - 3; i++) {
		if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6') {
			return true;
		}
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 666 << endl;
		return 0;
	}
	int cnt = 1;
	int i = 1665;
	while (true) {
		if (cnt == n) {
			break;
		}
		string str = to_string(i);
		if (is666(str)) {
			cnt++;
		}
		i++;
	}
	printf("%d\n", i-1);
}