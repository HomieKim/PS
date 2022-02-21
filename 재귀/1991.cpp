#include <iostream>
#include <vector>
using namespace std;

int n;
pair<int, int> edge[26];
void preOrder(char cur) {
	
	if (cur == '.')return;
	cout << cur;
	preOrder(edge[cur - 'A'].first);
	preOrder(edge[cur - 'A'].second);
}


void inOrder(char cur) {
	
	if (cur == '.')return;
	inOrder(edge[cur - 'A'].first);
	cout << cur;
	inOrder(edge[cur - 'A'].second);
}

void postOrder(char cur) {
	if (cur == '.') return;
	postOrder(edge[cur - 'A'].first);
	postOrder(edge[cur - 'A'].second);
	cout << cur;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch, left, right;
		cin >> ch >> left >> right;
		edge[ch - 'A'] = { left,right };
	}
	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');

	return 0;
}