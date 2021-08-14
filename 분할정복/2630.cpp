#include <iostream>

// ���� Ʈ�� : Ʈ�� �ڷᱸ���� �ϳ��� �θ� ��� �Ʒ��� �ڽ� ��带 4��(Quad)�� ������ �ִ� Ʈ��
using namespace std;

int arr[129][129];
int blue=0, white=0;

void func(int x,int y, int n) {
	
	int oneCnt = 0;
	int zeroCnt=0;
	for (int i = x; i < x+n; i++) {
		for (int j = y; j < y+n; j++) {
			if (arr[i][j] == 1) {
				oneCnt++;
			}
			else if (arr[i][j] == 0) {
				zeroCnt++;
			}
		}
	}

	if (zeroCnt == 0 && oneCnt == n*n) {
		blue++;
		return;
	}
	else if (zeroCnt == n*n && oneCnt == 0) {
		white++;
		return;
	}
	int half = n / 2;
	func(x, y, half);
	func(x, y + half, half);
	func(x + half, y, half);
	func(x + half, y + half, half);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	func(0,0,n);

	cout << white << '\n' << blue << '\n';


}