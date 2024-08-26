#include <iostream>
#include <queue>
using namespace std;

int map[8][9];
int visited[8][9];
int dist[8][9];


int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int index;

void input() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 9; ++j) {
			char c;
			cin >> c;

			if (c == '_')
				map[i][j] = 0;
			else
				map[i][j] = -1;
		}
	}
}


void bfs(int sy, int sx) {

	queue<pair<int, int>> q;

	visited[sy][sx] = 1;
	map[sy][sx] = index;
	q.push({ sy, sx });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9)
				continue;

			if (map[ny][nx] == 0)
				continue;

			if (visited[ny][nx] == 1)
				continue;

			map[ny][nx] = index;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}

void make_group() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (map[i][j] != 0 && visited[i][j] == 0) {
				index++;

				bfs(i, j);
			}
		}
	}
}

int distance() {
	queue<pair<int, int>> q;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (map[i][j] == 1) {
				q.push({ i, j });
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = -1;
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9)
				continue;

			if (dist[ny][nx] != -1)
				continue;

			

			dist[ny][nx] = dist[y][x] + 1;

			if (map[ny][nx] == 2)
				return dist[ny][nx] - 1;

			q.push({ ny, nx });
		}
	}
}

void solution() {
	cout << distance();
}

int main() {
	input();

	make_group();

	solution();
}
