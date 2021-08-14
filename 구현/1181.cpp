#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, string>> vec;
	string a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		vec.push_back(make_pair(a.length(), a));
	}

	sort(vec.begin(), vec.end(), cmp);
	auto unit = unique(vec.begin(), vec.end());
	vec.erase(unit, vec.end());
	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].second << "\n";
	}

}