#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}
int main() {
	
	int n;
	cin >> n;

	vector<int> arr;
	int tmp;
	int sum = 0;
	int max = -4001;
	int min = 4001;
	int count[8002] = { 0 ,};
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		if (max < tmp) {
			max = tmp;
		}
		if (min > tmp) {
			min = tmp;
		}
		if (tmp < 0) {
			count[tmp * -1]++;
		}
		else {
			count[tmp + 4001]++;
		}
		
		arr.push_back(tmp);
	}
	
	// n���� ���� ���� n���� ���� ��
	cout << round((double)sum / n) << '\n';
	// �߾Ӱ�
	sort(arr.begin(), arr.end());
	cout << arr[(n / 2 + 1)-1] << '\n';
	// ���� ���� ��Ÿ���� ��
	vector<pair<int,int>> vec;
	for (int i = 0; i < 8002; i++) {
		if (count[i] != 0) {
			int tmp;
			if (i <= 4000) {
				tmp = i * -1;
			}
			else {
				tmp = i - 4001;
			}
			vec.push_back(make_pair(count[i], tmp));
		}
	}
	sort(vec.begin(), vec.end(), compare);
	if (vec.size() == 1) {
		cout << vec[0].second << '\n';
	}
	else {
		if (vec[0].first == vec[1].first) {
			cout << vec[1].second << '\n';
		}
		else {
			cout << vec[0].second << '\n';
		}
	}
	
	// �ִ밪 - �ּҰ�
	cout << max - min << '\n';

}