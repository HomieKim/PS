#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<int> rope;
int main() {
	int n;
	cin >> n;
	int tmp;
	int N = n;
	while (n--) {
		cin >> tmp;
		rope.push_back(tmp);
	}

	sort(rope.begin(), rope.end(), greater<int>());
	ll rst = 0;
	for (int i = 0; i < N; i++) {
		(rope[i] * (i + 1) > rst) ? rst = rope[i] * (i + 1) : rst = rst;
	}

	cout << rst << endl;
}