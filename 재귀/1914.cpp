#include <iostream>
#include <cmath>
#include <string>

using namespace std;
void hanoi(int size, int start, int by, int dest) {
	if (size == 1) {
		printf("%d %d\n", start, dest);
	}
	else {
		hanoi(size - 1, start, dest, by);
		printf("%d %d\n", start, dest);
		hanoi(size - 1, by, start, dest);
	}
}
int main() {
	
	int n;
	cin >> n;
	string s = to_string(pow(2,n));
	int idx = s.find('.');
	string answer = s.substr(0, idx);
	answer[answer.length() - 1] -= 1;
	cout << answer  << endl;
	if (n <= 20) {
		//hanoi(n, 1, 2, 3);
	}
}