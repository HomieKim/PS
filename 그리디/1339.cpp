#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int n;
string s;
int alpaArr[27] = { 0, };
vector<string> strVec;
bool desc(int a, int b) {
	return a > b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		strVec.push_back(s);
	}

	for (string str : strVec) {
		int len = str.length();
		int tmp = 0;
		for (int i = 0; i < len; i++) {
			int arrNum = str[i] - 'A';
			alpaArr[arrNum] += pow(10, (len - i)-1);
			tmp++;
		}
	}
	sort(alpaArr, alpaArr + 27, desc);
	int ans = 0;
	int tmp = 9;
	for (int i = 0; i < 27; i++) {
		if (alpaArr == 0) break;
		ans += tmp * alpaArr[i];
		tmp--;
	}
	cout << ans << endl;

	

}