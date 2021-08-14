#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> vec;
int cnt = 1; 
bool cmp(pair<int,int>a, pair<int,int> b) {
	if (a.second == b.second) { 
		return a.first < b.first;	// first�� ���� �������� ����
//		return a.first > b.first; �� first�� ���� �������� ����
	}
	else {
		return a.second < b.second;	// second�� ���� �������� ����
//		return a.second > b.second; �� second�� ���� �������� ����			
	}
}
int main() {

	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end(), cmp);
	int nowTime = vec[0].second;
	for (int i = 1; i < n; i++) {
		if (vec[i].first < nowTime) {
			continue;
		}
		else {
			nowTime = vec[i].second;
			cnt++;
		}
	}
	cout << cnt << endl;


}