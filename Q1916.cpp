#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Coord {
	int to;
	int cost;

	bool operator < (Coord right) const {
		return this->cost < right.cost;
	}
};

int n, m;
int start_pos, end_pos;

vector<vector<Coord>> graph;
vector<int> dist;

void input() {

	cin >> n >> m;
	graph.resize(n + 1);
	dist.resize(n + 1, 21e8);

	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back({ to, cost });
	}

	cin >> start_pos >> end_pos;
}

void dijkstra(int start) {

	priority_queue<Coord> pq;

	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		Coord now = pq.top();
		pq.pop();

		if (dist[now.to] < now.cost) {
			continue;
		}

		for (int i = 0; i < graph[now.to].size(); ++i) {
			Coord next = graph[now.to][i];

			int next_cost = dist[now.to] + next.cost;

			if (dist[next.to] <= next_cost)
				continue;

			dist[next.to] = next_cost;
			pq.push({ next.to, next_cost });
		}
	}

}

int main() {

	input();

	dijkstra(start_pos);

	cout << dist[end_pos];
}