#include <iostream>
#include <algorithm>

using namespace std;

int L, V, P;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	int cnt = 1;
	// �����ϴ� 8��V �� 5��L�� ��밡�� �ް� 20��V
	while (true) {
		cin >> L >> P >> V;
		if (L == 0 && V == 0 && P == 0) break;
		ans = (V / P) * L + min(V % P, L);
		cout << "Case " << cnt << ": " << ans << endl;
		ans = 0;
		cnt++;
	}

}