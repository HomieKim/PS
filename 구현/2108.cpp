#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[8002] = { 0, };
int main() {
	int n;
	cin >> n;

	vector<int> vec;
	int num;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		vec.push_back(num);
		if (num < 0) {
			arr[num * -1]++;
		}
		else {
			arr[num + 4001]++;
		}

	}

	sort(vec.begin(), vec.end());
	int maxEl = *max_element(arr, arr + 8002);
	vector<int> tmpVec;
	for (int i = 0; i < 8002; i++) {
		if (maxEl == arr[i]) {
			tmpVec.push_back(i);
		}
	}

	int rst = 0;
	if (tmpVec.size() > 1) {
		for (int i = 0; i < tmpVec.size(); i++) {
			if (tmpVec[i] >= 4001) {
				tmpVec[i] -= 4001;
			}
			else {
				tmpVec[i] *= -1;
			}
		}
		sort(tmpVec.begin(), tmpVec.end());
		rst = tmpVec[1];
	}
	else {
		rst = tmpVec[0];
		if (rst >= 4001) {
			rst -= 4001;
		}
		else {
			rst *= -1;
		}
	}
	// »ê¼úÆò±Õ
	double avg = round(sum / (double)n);
	if (avg == -0) {
		avg = 0;
	}
	cout << avg << '\n';
	// Áß¾Ó°ª
	cout << vec[(n / 2 + 1) - 1] << '\n';
	// ÃÖºó°ª
	cout << rst << '\n';
	// ¹üÀ§
	cout << vec[n - 1] - vec[0] << '\n';

}