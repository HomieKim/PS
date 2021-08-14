#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;



int main() {
	//계수 정렬 10000이하의 자연수가 조건으로 주어짐

	int n;
	scanf("%d", &n);
	int arr[10001] = { 0, };
	int a;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		arr[a]++;
	}
	for (int i = 0; i < 10001; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) {
				printf("%d\n", i);
			}
		}

	}

}