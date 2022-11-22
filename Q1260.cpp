#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> isVisited;
int n, m;

void dfs(int cur);
void bfs(int start);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v;
	cin >> n >> m >> v;

	graph.assign(n + 1, vector<int> (0, 0));
	isVisited.assign(n + 1, false);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << "\n";
	isVisited.assign(n + 1, false);
	bfs(v);
}

void dfs(int cur) {
	isVisited[cur] = true;

	cout << cur << " ";
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (!isVisited[next]) dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	isVisited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!isVisited[next]) {
				q.push(next);
				isVisited[next] = true;
			}
		}
	}
}