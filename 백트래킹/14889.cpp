#include <iostream>

using namespace std;

int n;
int S[21][21];
int rst = 10000001;
bool vis[22];

void func(int num,int cnt) {

	if (cnt == n / 2) {
		int start, link;
		start = 0;
		link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i] == true && vis[j] == true) start += S[i][j];
				if (vis[i] == false && vis[j] == false) link += S[i][j];
			}
		}

		if (rst > abs(start - link)) rst = abs(start - link);
		return;
	}

	for (int i = num; i < n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			func(i + 1, cnt + 1);
			vis[i] = false;
		}
	}

}
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> S[i][j];
		}
	}
	
	func(0,0);
	cout << rst << '\n';
}