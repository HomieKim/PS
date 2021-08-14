#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;


void hanoi(int n, int a, int b, int c) {
	
	if (n == 1) {
		printf("%d %d\n", a, c);
	}
	else {
		hanoi(n - 1, a, c, b);
		printf("%d %d\n", a, c);
		hanoi(n - 1, b, a, c);
	}
	
}

int main() {
	int n;
	cin >> n;
	cout << (int)pow(2,n)-1 << endl;
	hanoi(n ,1,2,3);
	
	
}