#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> vec;
	vector<int> vec2;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		vec.push_back(a);
		vec2.push_back(a);
	}
	sort(vec.begin(), vec.end());
	auto uniq = unique(vec.begin(), vec.end());
	vec.erase(uniq, vec.end());
	for (int a : vec2) {
		cout << lower_bound(vec.begin(), vec.end(), a) - vec.begin() << ' ';
	}

}