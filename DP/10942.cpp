#include <iostream>
#include <stdio.h>
#define MAX 2001
using namespace std;
int N, M;
int arr[MAX];
int dp[MAX][MAX];

void setPalindrom() {
	// 길이가 1일때랑 2일때 초깃값으로 구함
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
		if (i > 1 && arr[i - 1] == arr[i]) {
			dp[i - 1][i] = 1;
		}
	}

	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= N-i; j++) {
			if (arr[j] == arr[j+i] && dp[j + 1][j + i - 1] == 1) {
				dp[j][j+i] = 1;
			}
		}
	}
	
}
int main() {
	
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	setPalindrom();
	scanf("%d", &M);
	int S, E;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &S, &E);
		printf("%d\n", dp[S][E]);
	}
}