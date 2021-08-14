#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

ll rst = 0;
ll n;
ll dis[100003];
ll price[100003];
int main() {
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> dis[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	
	ll minPrice = price[0];

	for (int i = 0; i < n; i++) {
		if (minPrice > price[i]) {
			minPrice = price[i];
		}

		rst += minPrice * dis[i];
	}
	cout << rst << endl;
}