#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> vec;
int main() {
	string s;
	cin >> s;
	string tmp = "";
	for (int i = 0; i <= s.size(); i++) {
		if (i == s.size()) {
			vec.push_back(tmp);
		}
		if (s[i] == '+' || s[i] == '-') {
			vec.push_back(tmp);
			tmp = s[i];
			vec.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += s[i];
		}
	}
	int rst = 0;
	int flag = 1;
	for (auto a : vec) {
		if (flag == 1) {
			if (a == "+") {
				continue;
			}
			else if (a == "-") {
				flag = 0;
			}
			else {
				rst += stoi(a);
			}
		}
		else {
			if (a == "+" || a == "-") continue;
			rst -= stoi(a);
			
		}
	}
	cout << rst << endl;
}
