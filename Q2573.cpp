#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> map;

struct Coord {
	int y;
	int x;
	int cost;
};
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> n >> m;

	map.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
}

int time;

vector<vector<int>> visited;

void dfs(int y, int x) {

	visited[y][x] = 1;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;

		if (visited[ny][nx] == 1)
			continue;

		if (map[ny][nx] == 0)
			continue;
			
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
	
	return;
}

void updateMap() {
	vector<Coord> changeCoord;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			if (map[i][j] == 0)
				continue;

			int zeroCnt = 0;

			for (int d = 0; d < 4; ++d) {
				int ny = i + dy[d];
				int nx = j + dx[d];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;

				if (map[ny][nx] == 0)
					zeroCnt++;
			}

			if (zeroCnt == 0)
				continue;
	
			int tmp = (map[i][j] - zeroCnt < 0) ? 0 : map[i][j] - zeroCnt;
			changeCoord.push_back({ i, j, tmp });
		}
	}

	for (int i = 0; i < changeCoord.size(); ++i) {
		Coord now = changeCoord[i];

		map[now.y][now.x] = now.cost;
	}
}

void solution() {

	while (1) {
		int cnt = 0; // ºù»ê µ¢¾î¸® Ä«¿îÆ®
		int flag = 0;

		visited.clear();
		visited.assign(n, vector<int>(m, 0));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (visited[i][j] == 0 && map[i][j] != 0) {

					dfs(i, j);
					flag = 1;
					cnt++;
				}
			}
		}

		if (cnt >= 2) {
			cout << time;
			return;
		}

		// ´Ù ³ìÀ½
		if (flag == 0) {
			cout << 0;
			return;
		}

		updateMap();
		time++;
	
	}
	
}

int main() {

	input();

	solution();
}