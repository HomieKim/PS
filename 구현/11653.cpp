#include <iostream>
#include <vector>

using namespace std;
bool isSosu(int num) {
	if (num == 1) {
		return false;
	}
	int flag = 0;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	
	int n;
	cin >> n;
	vector<int> list;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0 && isSosu(i)==true) {
			list.push_back(i);
		}
	}

	for (int i = 0; i < list.size(); i++) {

		while (n % list[i] == 0) {
			cout << list[i] << endl;
			n /= list[i];
		}

	}


	

	
}