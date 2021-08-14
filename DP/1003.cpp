#include <iostream> 

using namespace std;
int T, n, oneCnt=0, zeroCnt=0;
int list[41];
int fibo(int n) {
	if (n < 2) {
		return list[n];
	}
	if (list[n] != 0) {
		return list[n];
	}
	else {
		return list[n] = fibo(n - 1) + fibo(n - 2);
	}

}
int main() {
	cin >> T;
	list[0] = 0;
	list[1] = 1;
	for (int i = 0; i < T; i++) {
		cin >> n;
		if (n == 1) {
			cout << 0 << " " << 1 << '\n';
		}
		else if (n == 0) {
			cout << 1 << " " << 0 << '\n';
		}
		else {
			cout << fibo(n-1) << " " <<fibo(n) << '\n';
		}
	}
   
}