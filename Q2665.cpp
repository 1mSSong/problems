#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;
vector<vector<int>> visited;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> n;

	map.resize(n, vector<int>(n, 0));
	visited.resize(n, vector<int>(n, 21e8));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
}

void bfs() {

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			int now = visited[y][x] + (!map[ny][nx]);

			if (now >= visited[ny][nx])
				continue;

			visited[ny][nx] = now;
			q.push({ ny, nx });
		}
	}
}

int main() {
	input();

	bfs();

	cout << visited[n - 1][n - 1];
}
