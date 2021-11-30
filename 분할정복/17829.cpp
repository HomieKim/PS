#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[1025][1025];
int get_second_num(int i, int j) {
	vector<int> vec;
	vec.push_back(map[i][j]);
	vec.push_back(map[i][j+1]);
	vec.push_back(map[i+1][j]);
	vec.push_back(map[i+1][j+1]);
	sort(vec.begin(), vec.end());
	return vec[2];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	while (n > 1) {
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < n; j += 2) {
				map[i / 2][j / 2] = get_second_num(i, j);
			}
		}
		n /= 2;
	}

	cout << map[0][0] << endl;
}