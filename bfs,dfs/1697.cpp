#include <iostream>
#include <queue>

using namespace std;
int dis[100001];
int n, k;
int main() {
	cin >> n >> k;

	queue<int> Q;
	Q.push(n);
	fill(dis, dis + 100001, -1);
	dis[n] = 0;
	while (dis[k] == -1) {
		int cur = Q.front();
		Q.pop();

		for (int nxt : {cur - 1, cur+1, 2*cur}) {
			if (nxt < 0 || nxt >100001) continue;
			if (dis[nxt] != -1) continue;

			dis[nxt] = dis[cur] + 1;
			Q.push(nxt);
		}
	}

	cout << dis[k] << endl;

}