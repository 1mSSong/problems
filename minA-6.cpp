#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;
int n, m;

vector<vector<int>> map;
// 0 - 1 : 시작, 2 - 3 ; 도착, 4 : 연료 소모
vector<vector<int>> tunnel;
vector<vector<int>> visited; // 연료 소모량

// 방향 : 상 하 좌 우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


void init() {
	map.clear();
	tunnel.clear();
	visited.clear();
}

void input() {
	cin >> n >> m;

	map.assign(n, vector<int>(n, 0));
	visited.assign(n, vector<int>(n, 2e9));
	tunnel.resize(m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < m; ++i) {
		tunnel[i].resize(5);

		for (int j = 0; j < 4; ++j) {
			int tmp;
			cin >> tmp;
			tunnel[i][j] = tmp - 1;
		}
		cin >> tunnel[i][4];
	}
}


void bfs(int sy, int se) {
	queue<pair<int, int>> q;

	visited[sy][se] = 0;
	q.push({ sy, se });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			// 평지
			if (map[y][x] == map[ny][nx]) {
				if (visited[ny][nx] > visited[y][x] + 1) {
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny, nx });
				}
				
			}
			// 오르막길
			else if (map[ny][nx] > map[y][x]) {
				if (visited[ny][nx] > visited[y][x] + (map[ny][nx] - map[y][x]) * 2) {
					visited[ny][nx] = visited[y][x] + (map[ny][nx] - map[y][x]) * 2;
					q.push({ ny, nx });
				}
			}
			// 내리막길
			else if (map[ny][nx] < map[y][x]) {
				if (visited[ny][nx] > visited[y][x]) {
					visited[ny][nx] = visited[y][x];
					q.push({ ny, nx });
				}
			}
		}

		// 터널 있는지 찾기
		int flag1 = -1;
		int flag2 = -1;
		for (int j = 0; j < m; ++j) {
			if (tunnel[j][0] == y && tunnel[j][1] == x) {
				flag1 = j;
				break;
			}
			else if (tunnel[j][2] == y && tunnel[j][3] == x) {
				flag2 = j;
				break;
			}
		}

		// 터널 X
		if (flag1 == -1 && flag2 == -1)
			continue;
		int ny = 0, nx = 0, cost = 0;

		if (flag1 != -1) {
			ny = tunnel[flag1][2];
			nx = tunnel[flag1][3];
			cost = tunnel[flag1][4];
		}
		else if (flag2 != -1) {
			ny = tunnel[flag2][0];
			nx = tunnel[flag2][1];
			cost = tunnel[flag2][4];
		}
		

		// 터널 O
		if (visited[ny][nx] > visited[y][x] + cost) {
			visited[ny][nx] = visited[y][x] + cost;
			q.push({ ny, nx });
		}
	
	}
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		bfs(0, 0);

		cout << "#" << tc << " " << visited[n - 1][n - 1] << endl;
	}
}