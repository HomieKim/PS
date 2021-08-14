#include <iostream>
#include <queue>
#include <vector>

#define MAX 20001

using namespace std;
int k, v, e, a,b;
queue<int> Q;

vector<int> graph[MAX];
int vis[MAX];	//  0 -> 방문 안한거  ,,, 1그룹 -1그룹 나눔


void bfs(int start) {
	Q.push(start);
	vis[start] = 1;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			if (vis[graph[cur][i]] == 0) {	// 방문하지 않은 노드일 때
				Q.push(graph[cur][i]);	// 다음 노드를 큐에 넣어 줌
				vis[graph[cur][i]] = vis[cur] * -1; // 방문 처리
			}
		}
	}
}
bool isBipartite() {
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			if (vis[i] == vis[graph[i][j]]) {
				return false;
			}
		}
	}
	return true;
}
void init() {
	for (int i = 0; i < 20001; i++) {
		graph[i].clear();
		vis[i] = 0;
	}
	Q = queue<int>();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> v >> e;
		for (int j = 0; j < e; j++) {
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}


		for (int i = 0; i < v; i++) {
			if (vis[i] == 0) {
				bfs(i);
			}
		}

		if (isBipartite()) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}

		init();
	}
}