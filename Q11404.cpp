#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct coord {
	int to;
	int cost;

	bool operator <(coord right) const {
		return cost > right.cost;
	}
};

int n, m;
vector<vector<int>> answer;
vector<vector<int>> graph;

void input() {
	cin >> n >> m;

	answer.resize(n + 1, vector<int>(n + 1, 21e8));
	graph.resize(n + 1, vector<int>( n +1, 0));
	
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		if (graph[a][b] == 0) {
			graph[a][b] = c;
		}
		else {
			graph[a][b] = min(graph[a][b], c);
		}
	}

}

void dijkstra(int start) {

	priority_queue<coord> pq;
	pq.push({ start, 0 });
	answer[start][start] = 0;

	while (!pq.empty()) {

		coord now = pq.top();
		pq.pop();

		if (now.cost > answer[start][now.to])
			continue;

		for (int i = 1; i <= n; ++i) {
			int next = graph[now.to][i];

			if (next == 0)
				continue;

			int next_cost = answer[start][now.to] + next;

			if (next_cost >= answer[start][i])
				continue;

			answer[start][i] = next_cost;
			pq.push({ i, next_cost });
		}

	}
}

void solution() {

	for (int i = 1; i <= n; ++i) {
		dijkstra(i);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {

			if (answer[i][j] == 21e8)
				answer[i][j] = 0;

			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	
	input();

	solution();
}