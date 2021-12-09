#include <iostream>
#define MAX 1000001
using namespace std;

int arr[MAX];
int main() {

	int n, h;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		if (arr[h+1] != 0) {
			arr[h + 1]--;
			arr[h]++;
		}
		else {
			arr[h]++;
			cnt++;
		}
		
	}

	cout << cnt << endl;
}