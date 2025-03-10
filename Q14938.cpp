#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct coord {
	int to;
	int cost;

	bool operator < (coord right) const {
		return cost < right.cost;
	}
};

int n, m, r;
int answer;

vector<vector<coord>> graph;
vector<int> item;

void input() {
	cin >> n >> m >> r;

	graph.resize(n + 1);
	item.resize(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> item[i];
	}

	for (int i = 0; i < r; ++i) {
		int a, b, l;
		cin >> a >> b >> l;

		graph[a].push_back({ b, l });
		graph[b].push_back({ a, l });
	}
}

void dijkstra(int start) {
	
	vector<int> dist;
	dist.resize(n + 1, 21e8);

	priority_queue<coord> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		coord now = pq.top();
		pq.pop();

		if (now.cost > dist[now.to])
			continue;

		for (int i = 0; i < graph[now.to].size(); ++i) {
			coord next = graph[now.to][i];

			int next_cost = dist[now.to] + next.cost;

			if (next_cost >= dist[next.to])
				continue;

			dist[next.to] = next_cost;
			pq.push({ next.to, next_cost });
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (dist[i] > m)
			continue;

		sum += item[i];
	}

	answer = max(answer, sum);
}

void solution() {
	
	for (int i = 1; i <= n; ++i) {
		dijkstra(i);
	}

	cout << answer;
}

int main() {

	input();

	solution();
}