#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

vector<int> graph[MAX];
queue<int> que;
int vis[MAX];
int n, m, cnt=0;

//void dfs(int node) {
//	
//	vis[node] = 1;
//
//	for (int i = 0; i < graph[node].size(); i++) {
//		int next = graph[node][i];
//		if (vis[next] == 0) { // 연결된 다음노드가 방문하지 않았다면 탐색시작
//			dfs(next);
//		}
//	}
//}
//
//int main() {
//	cin >> n >> m;
//
//	int a, b;
//	for (int i = 1; i <= m; i++) {
//		cin >> a >> b;
//		graph[a].push_back(b);
//		graph[b].push_back(a);
//	}
//
//	for (int i = 1; i <= n; i++) {
//		if (vis[i] == 0) {	// 방문하지 않았다면 탐색 시작
//			cnt++;
//			dfs(i);
//		}
//	}
//
//	cout << cnt << endl;
//}
void bfs(int node) {

	vis[node] = 1;
	que.push(node);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i = 0; i <graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (vis[next] == 0) {
				vis[next] = 1;
				que.push(next);
			}
		}
	}


}
int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 1;i <= m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}