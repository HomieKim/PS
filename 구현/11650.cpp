#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}
int main() {
	int a,b,n;
	cin >> n;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vec.push_back(make_pair(a,b));
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}

}