#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int n, m;
int answer;

vector<vector<int>> map, tmp, now_map;
vector<pii> emptyCell;

int path[3];

queue<pii> vir; // 바이러스 위치

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	
	cin >> n >> m;

	map.resize(n, vector<int>(m, 0));
	tmp.resize(n, vector<int>(m, 0));
	now_map.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			cin >> map[i][j];
			
			if (map[i][j] == 0) {

				emptyCell.push_back({ i, j });
			}
			else if (map[i][j] == 2) {
				vir.push({ i, j });
			}
		}
	}
}

void bfs() {

	now_map = tmp;


	queue<pii> q = vir;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (now_map[ny][nx] != 0)
				continue;

			now_map[ny][nx] = 2;
			q.push({ ny, nx });
		}
	}
	

	int now_answer = 0;

for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			if (now_map[i][j] == 0)
				now_answer++;
		}
	}

	answer = max(now_answer, answer);
}

void dfs(int now, int y, int x) {

	if (now == 3) {

		bfs();
		
		return;
	}

	for (int i = 0; i < emptyCell.size(); ++i) {

		if (now > 0 && path[now - 1] >= i)
			continue;

		int ny = emptyCell[i].first;
		int nx = emptyCell[i].second;

		if (tmp[ny][nx] != 0)
			continue;

		tmp[ny][nx] = 3;
		path[now] = i;

		dfs(now + 1, ny, nx);

		tmp[ny][nx] = 0;
		path[now] = -1;

	}

}

void solution() {

	tmp = map;

	dfs(0, emptyCell[0].first, emptyCell[1].second);

	cout << answer;
}

int main() {

	input();

	solution();
}