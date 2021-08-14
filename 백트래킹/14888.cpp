#include<iostream>
#include <algorithm>
using namespace std;

int MAX = -1000000000; // -10억
int MIN = 1000000000; // 10억

int Operator[4]; // 연산자
int num[11]; // 입력 순열
int N;

void func(int rst, int idx)
{
	if (idx == N - 1) {
		MAX = max(rst, MAX);
		MIN = min(rst, MIN);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (Operator[i] > 0) {
			Operator[i]--;
			if (i == 0) {
				func(rst + num[idx + 1], idx + 1);
			}
			else if (i == 1) {
				func(rst - num[idx + 1], idx + 1);
			}
			else if (i == 2) {
				func(rst * num[idx + 1], idx + 1);
			}
			else if (i == 3) {
				func(rst / num[idx + 1], idx + 1);
			}
			Operator[i]++;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> Operator[i];
	}

	func(num[0], 0);

	cout << MAX << "\n" << MIN;
}