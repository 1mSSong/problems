#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> map;
queue<pair<int, int>> one;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> m >> n;

	map.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				one.push({ i, j });
			}

			if (map[i][j] == 0) {
			}
		}
	}
}

void bfs() {

	while (!one.empty()) {
		int y = one.front().first;
		int x = one.front().second;
		
		one.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (map[ny][nx] == 0) {
				map[ny][nx] = map[y][x] + 1;
				
				one.push({ ny, nx });
			}
		}
	}

}


void output() {
	
	int max = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 0) {
				cout << "-1\n";
				return;
			}

			if (map[i][j] > max)
				max = map[i][j];
		}
	}

	cout << max - 1;
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();

	bfs();

	output();
}