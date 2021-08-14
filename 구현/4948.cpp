#include <iostream>
#include <cmath>
#define MAX 123456*2+1
using namespace std;

int allPrime[MAX];
int main() {
	
	while (true) {

		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 2; i <= 2 * n; i++) {
			allPrime[i] = i;
		}

		for (int i = 2; i <= 2 * n; i++) {
			if (allPrime[i] == 0) continue;
			for (int j = i + i; j <= 2 * n; j+=i) {
				allPrime[j] = 0;
			}
		}

		int cnt = 0;
		for (int i = n+1; i <= 2 * n; i++) {
			if (allPrime[i] != 0) {
				cnt++;
			}
		}

		cout << cnt << endl;
	}


}