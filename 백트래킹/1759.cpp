#include <iostream>
#include <algorithm>
using namespace std;


char pw[16];
int L, C;
bool isVow(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
		return true;
	}
	else {
		return false;
	}
}
void solve(int now, string str, int cons, int vow) {
	if (str.size() == L) {
		if (cons >= 2 && vow >= 1) {
			cout << str << '\n';
		}
		return;
	}

	for (int i = now; i < C; i++) {
		if (isVow(pw[i])) {
			solve(i+ 1, str + pw[i], cons, vow + 1);
		}
		else {
			solve(i + 1, str + pw[i], cons+1, vow);
		}
	}
}
int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> pw[i];
	}

	sort(pw, pw+C);

	solve(0,"",0,0);
		
}