#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool group(string str) {
	bool check = true;
	if (str.size() <= 2) {
		return check;
	}

	vector<char> arr;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] != str[i + 1]) {
			arr.push_back(str[i]);
		}
	}
	arr.push_back(str[str.size() - 1]);
	for (int k = 0; k < arr.size()-1; k++) {
		for(int m = k+1;m<arr.size();m++)
		if (arr[k] == arr[m]) {
			check = false;
			return check;
		}
	}
	return check;
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if (group(str)) {
			cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}