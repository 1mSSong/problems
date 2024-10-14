#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct coord {
	int z, y, x;
};

int n, m, h;

vector <vector<vector<int>>> map;
vector <vector<vector<int>>> visited;

queue<coord> q;
int answer = -1;

int dz[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };


void input() {
	cin >> m >> n >> h;

	map.assign(h, vector<vector<int>>(n, vector<int>(m, 0)));
	visited.assign(h, vector<vector<int>>(n, vector<int>(m, 21e8)));

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				cin >> map[i][j][k];

				if (map[i][j][k] == 1) {
					visited[i][j][k] = 0;
					q.push({ i, j, k });
				}
			}
		}
	}
}

void solution() {
	while (!q.empty()) {
		coord now = q.front();
		q.pop();

		for (int i = 0; i < 6; ++i) {
			int nz = now.z + dz[i];
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h)
				continue;

			if (map[nz][ny][nx] == -1)
				continue;
			
			if (visited[nz][ny][nx] > visited[now.z][now.y][now.x] + 1) {
				visited[nz][ny][nx] = visited[now.z][now.y][now.x] + 1;
				q.push({ nz, ny, nx });
			}
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				
				if (map[i][j][k] == -1)
					continue;

				if (map[i][j][k] == 0 && visited[i][j][k] == 21e8) {
					answer = -1;
					return;
				}

				answer = max(answer, visited[i][j][k]);
			}
		}
	}
}

int main() {
	input();

	solution();

	cout << answer;
	return 0;
}