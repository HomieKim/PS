#include <iostream>
#include <string>

using namespace std;
bool isPalindrom(string s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main() {

	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		string tmp = s.substr(i, s.size() - i);
		if (isPalindrom(tmp)) {
			ans = s.size() + i;
			break;
		}
	}	
	cout << ans << endl;
}