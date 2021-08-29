#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int arr[1001];
vector<int> sumTwo;
int n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sumTwo.push_back(arr[i] + arr[j]);
		}
	}
	
	sort(sumTwo.begin(), sumTwo.end());
	
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(sumTwo.begin(), sumTwo.end(), arr[i] - arr[j])) {
				cout << arr[i];
				return 0;
			}
		}
	}
}