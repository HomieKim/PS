#include <iostream>
#include <vector>
using namespace std;
int n, k;

vector<int> vec;
int cnt = 0;
int main() {

	cin >> n >> k;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp <= k) {
			vec.push_back(tmp);
		}
		
	}

	for (int i = vec.size()-1; i >= 0; i--) {
		if (vec[i] <= k) {
			cnt += k / vec[i];
			k = k % vec[i];
		}
	}
	cout << cnt << endl;
}