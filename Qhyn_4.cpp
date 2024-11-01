#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef pair<int, int> p;

int n, m;

// 벽: -1, 길: 0, R: 1, G: 2, B: 3
vector<vector<int>> map;
vector<p> RGB[3];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int answer = 21e8;
int sum;

void input() {
	cin >> n >> m;
	
	map.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;

			if (c == '#') {
				map[i][j] = -1;
			}

			else if (c == 'R') {
				map[i][j] = 1;
				RGB[0].push_back({ i, j });
			}
				
			else if (c == 'G') {
				map[i][j] = 2;
				RGB[1].push_back({ i, j });
			}
	
			else if (c == 'B') {
				map[i][j] = 3;
				RGB[2].push_back({ i, j });
			}
				
		}
	}
}

// 불가능 : -1, 가능하면 : 최소 연료 return
int bfs(p e) {
	vector<vector<int>> visited;
	visited.assign(n, vector<int>(m, -1));

	if (map[0][0] == -1)
		return -1;

	queue<p> q;
	q.push({ 0, 0 });
	visited[0][0] = 0;

	while (!q.empty()) {
		p now = q.front();
		q.pop();

		if (now == e)
			break;

		for (int i = 0; i < 4; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (map[ny][nx] == -1)
				continue;

			if (visited[ny][nx] != -1)
				continue;

			visited[ny][nx] = visited[now.first][now.second] + 1;
			q.push({ ny, nx });
		}
	}

	return visited[e.first][e.second];
}

// level - 0: R, 1: G, 2: B
void dfs(int level) {
	if (level == 3) {
		if (sum == -1)
			return;

		answer = min(sum, answer);
		return;
	}

	
	for (int i = 0; i < RGB[level].size(); ++i) {
		
		// 현재 가능한 주차 X
		int now = bfs(RGB[level][i]);

		if (now == -1)
			continue;

		sum += now;
		map[RGB[level][i].first][RGB[level][i].second] = -1;

		dfs(level + 1);
		
		sum -= now;
		map[RGB[level][i].first][RGB[level][i].second] = level + 1;
	}
}


int main() {
	input();

	dfs(0);

	(answer == 21e8) ? answer = -1 : 1;
	cout << answer;

}