#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct coord {
	int num;
	int cost;

	bool operator< (const coord& right) const {
		return this->cost < right.cost;
	}
};

int n, e;
int v[2];
long long answer;

vector<vector<coord>> graph;
vector<vector<int>> dist;

void input() {
	cin >> n >> e;

	graph.resize(n + 1);
	dist.resize(3, vector<int>(n + 1, 21e8));

	for (int i = 0; i < e; ++i) {
		
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	cin >> v[0] >> v[1];
}

void dijkstra(int start, int order) {
	
	priority_queue<coord> pq;
	pq.push({ start, 0 });
	dist[order][start] = 0;

	while (!pq.empty()) {
		coord now = pq.top();
		pq.pop();

		if (now.cost > dist[order][now.num])
			continue;

		for (int i = 0; i < graph[now.num].size(); ++i) {
			coord next = graph[now.num][i];
			int next_cost = dist[order][now.num] + next.cost;

			if (next_cost >= dist[order][next.num])
				continue;

			dist[order][next.num] = next_cost;
			pq.push({ next.num, next_cost });

		}
	}
}

void printAnswer() {
	long long path1 = 21e8;
	long long path2 = 21e8;


	if (dist[2][v[1]] == 21e8) {
		answer = -1;
		return;
	}


	if (dist[0][v[0]] == 21e8 || dist[1][v[1]] == 21e8) {
		path1 = 21e8;
	}
	else {
		path1 = dist[0][v[0]] + dist[1][v[1]] + dist[2][v[1]];
	}


	if (dist[0][v[1]] == 21e8 || dist[1][v[0]] == 21e8) {
		path2 = 21e8;
	}
	else {
		path2 = dist[0][v[1]] + dist[1][v[0]] + dist[2][v[1]];
	}

	answer = min(path1, path2);

	if (answer >= 21e8) answer = -1;

}


int main() {

	input();

	dijkstra(1, 0);
	dijkstra(n, 1);
	dijkstra(v[0], 2);

	printAnswer();

	cout << answer;
}