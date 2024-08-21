#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Coord {
	int y, x;
	int cost;

	bool operator < (Coord right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;

		return false;
	}
};


vector<vector<int>> map;
vector<vector<int>> dist;

void input() {
	cin >> n >> m;
	
	map.assign(n, vector<int>(m, 0));
	dist.assign(n, vector<int>(m, 2e9));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
}

void dijkstra(int y, int x) {
	priority_queue<Coord> pq;
	
	dist[y][x] = map[y][x];
	pq.push({ y, x, map[y][x] });

	while (!pq.empty()) {
		Coord now = pq.top();
		pq.pop();

		if (dist[now.y][now.x] < now.cost)
			continue;

		for (int i = 0; i < 4; ++i) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			int nextCost = now.cost + map[ny][nx];

			if (dist[ny][nx] <= nextCost)
				continue;

			dist[ny][nx] = nextCost;
			pq.push({ ny, nx, nextCost });
		}
	}
	
}

int main() {
	input();

	dijkstra(0, 0);
	
	cout << dist[n - 1][m - 1];
}