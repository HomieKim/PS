#include <iostream> 
#include <cmath>

using namespace std;

int main() {
	int a;
	cin >> a;

	double rst1, rst2;
	const double pi = acos(-1);
	rst1 = (a * a) * pi;
	rst2 = (a * a) * 2;
	cout << fixed;
	cout.precision(6);
	cout << rst1 << endl;
	cout << rst2 << endl;

	




}