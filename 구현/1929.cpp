#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1000001

using namespace std;
int vec[MAX];

int main() {
	int a, b;
	
	cin >> a >> b;
	
	for (int i = 2; i <= b; i++) {
		vec[i] = i;
	}

	for (int i = 2; i <= sqrt(b); i++) {
		if (vec[i] == 0) continue;
		for (int j = i+i; j <= b; j += i) {
			vec[j] = 0;
		}
	}

	for (int i = a; i <= b; i++) {
		if (vec[i] != 0) {
			printf("%d\n", vec[i]);
		}
		
	}
}