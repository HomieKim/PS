#include <iostream>
#define ll long long 
using namespace std;

int main() {
	ll n;
	cin >> n;
	ll sum = 0;
	int i = 1;
	while (sum <= n) {
		sum += i;
		i++;
	}

	cout << i - 2 << endl;

}