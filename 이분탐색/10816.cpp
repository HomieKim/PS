#include <iostream> 
#include <algorithm>

using namespace std;
int n, m;
int arr[500002];

int upper(int start, int end,int target) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] > target) end = mid;
		else start = mid + 1;
	}
	return start;

}
int lower(int start, int end, int target) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] >= target) end = mid;
		else start = mid + 1;
	}
	return start;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	int num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << upper(0, n, num) - lower(0, n, num) << " ";
	}

}