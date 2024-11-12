#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;


int n;

vector<vector<int>> map;
vector<vector<int>> visited;

int h;

int answer;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> n;

	map.assign(n, vector<int>(n, 0));
	visited.assign(n, vector< int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];

			h = max(map[i][j], h);
		}
	}
}

void dfs(int y, int x) {
	
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;

		if (visited[ny][nx])
			continue;

		if (map[ny][nx] <= h)
			continue;

		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

void solution() {

	while (1) {
		int now = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {

				if (visited[i][j])
					continue;

				if (map[i][j] <= h)
					continue;

				visited[i][j] = 1;
				dfs(i, j);

				now++;
			}
		}

		answer = max(now, answer);
		h--;
		
		if (h == -1)
			break;

		visited.assign(n, vector<int>(n, 0));
	}
}

int main() {
	
	input();

	solution();

	cout << answer;
}