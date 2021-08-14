#include <iostream>
#define MAX 500001

int arr[MAX];
int rst[MAX];
long long cnt = 0;
using namespace std;
void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) {
			rst[k++] = arr[j++];
			cnt += (mid+1-i)*1LL;	// �����Ʈ�Ҷ� swap���� ���ϴ� �Ŵϱ� �������� �� ������ swap�Ͼ�� �Ÿ��� ���ϸ� ��
		}
		else {
			rst[k++] = arr[i++];
		}
	}

	if (i > mid) {
		while (j <= right) {
			rst[k++] = arr[j++];
		}
	}
	else {
		while (i <= mid) {
			rst[k++] = arr[i++];
		}
	}

	for (int a = left; a <= right; a++) {
		arr[a] = rst[a];
	}
}
void divide(int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		divide(left, mid);
		divide(mid + 1, right);
		merge(left, right);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	divide(0, n - 1);
	cout << cnt << endl;
}