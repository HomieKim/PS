#include <iostream>
#include <vector>
#define MAX 102
using namespace std;

int n, a, b, m, x, y;
vector<int> graph[MAX];
int visit[MAX];
int rst = -1;

void dfs(int start, int cnt) {
	visit[start] = 1;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (next == b) {
			rst = cnt;
			return;
		}
		if (!visit[next]) {
			dfs(next, cnt + 1);
		}
	}
}
int main() {

	cin >> n >> a >> b >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(a, 1);
	cout << rst << endl;
}