#include <iostream>
#include <string>

using namespace std;

int calc(string num) {
	int sum = 0;
	for (int i = 0; i < num.length(); i++) {
		sum += num[i]-'0';
	}
	sum += stoi(num);

	return sum;
}
int main() {
	string num;
	cin >> num;
	
	int a = stoi(num);
	string min;
	int i = 1;

	while (true) {
		int tmp = stoi(num) - i;
		if (tmp == 0) {
			break;
		}
		
		if (calc(to_string(tmp)) == a) {
			min = to_string(tmp);
		}
		i++;
	}
	
	if (min.empty()) {
		cout << 0 << endl;
	}
	else {
		cout << min << endl;
	}

}