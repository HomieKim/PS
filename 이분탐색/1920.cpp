#include <iostream>
#include <algorithm>
#define endl '\n'
#define MAX 100005

using namespace std;
int nArr[MAX];
int n, m;

void binary_search(int start, int end, int target) {

	int mid = (start + end) / 2;
	if (start > end) {
		cout << "0" << endl;
		return;
	}
	else {
		if (nArr[mid] == target) {
			cout << "1" << endl;;
			return;
		}
		else {
			if (nArr[mid] < target) {
				binary_search(mid + 1, end, target);

			}
			else if (nArr[mid] > target) {
				binary_search(start, mid - 1, target);
			}
		}


	}


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> nArr[i];
	}
	sort(nArr, nArr + n);
	cin >> m;
	int tmp;
	for (int i = 0; i < m; i++) {
		tmp = 0;
		cin >> tmp;
		binary_search(0, n - 1, tmp);
	}
}