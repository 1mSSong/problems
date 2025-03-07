#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int year;
int cheese; //  남은 치즈 개수

vector<vector<int>> map;

vector<vector<int>> air; // 외부 공기 여부

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {

	cin >> n >> m;
	map.resize(n, vector<int>(m, 0));
	air.resize(n, vector<int>(m, 0));
	
	for (int i = 0; i < n;++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];

			if (map[i][j])
				cheese++;

		}
	}
}


void bfs(pii start) {
	vector<vector<int>> visited;
	visited.resize(n, vector<int>(m, 0));

	queue<pii> q;
	visited[start.first][start.second] = 1;
	air[start.first][start.second] = 1;
	q.push({ start.first, start.second });

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (visited[ny][nx])
				continue;

			if (map[ny][nx])
				continue;

			visited[ny][nx] = 1;
			air[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}


void removeCheese() {
	vector<vector<int>> tmp_map;
	vector<vector<int>> tmp_air;

	tmp_map = map;
	tmp_air = air;

	pii start = { 0, 0 };

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			if (!map[i][j])
				continue;

			int cnt = 0;

			for (int d = 0; d < 4; ++d) {
				int ny = i + dy[d];
				int nx = j + dx[d];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;

				if (map[ny][nx])
					continue;

				if (!air[ny][nx])
					continue;

				cnt++;
			}

			if (cnt >= 2) {
				tmp_map[i][j] = 0;
				tmp_air[i][j] = 1;
				start = { i, j };
				cheese--;
			}
			 
			if (cheese == 0)
				return;
		}
	}

	map = tmp_map;
	air = tmp_air;

	
	bfs(start);
}

void solution() {
	
	// 외부 공기 체크
	bfs({ 0, 0 });

	while (cheese > 0) {

		removeCheese();
		
		year++;
	}	

	cout << year;
}

int main() {

	input();

	solution();
}