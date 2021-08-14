#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, max;
	cin >> n >> max;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}
	int sum = 0;
	int min = 999999;
	int rst = 0;
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++) {
			for (int m = 0;m< vec.size(); m++) {
				if (vec[i] != vec[j] && vec[i] != vec[m] && vec[j] != vec[m]) {
					sum = vec[i] + vec[j] + vec[m];
					if (sum == max) {
						cout << sum << endl;
						return 0;
					}
					else if (sum > max) {
						continue;
					}
					else if(min > max-sum) {
						min = max - sum;
						rst = sum;
					}
				}
			}
		}
	}
	cout << rst << endl;
}