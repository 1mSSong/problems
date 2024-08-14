#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int limit;
int group = 4;

pair<int, int> snowman;
pair<int, int> bell;
vector<vector<int>> map;
vector<vector<int>> cnt;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> n >> m;
	
	map.assign(n, vector<int>(m, 0));
	cnt.assign(n, vector<int>(m, 2e9));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				snowman = { i, j };
			}
			 
			if (map[i][j] == 3) {
				bell = { i, j };
			}
		}
	}
}

void bfs(int sy, int sx) {
	queue<pair<int, int>> q;

	q.push({ sy, sx });
	cnt[sy][sx] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		// 상 하
		for (int i = 0; i < 2; ++i) {
			int ny = y;
			int nx = x;
			int prevCnt = cnt[y][x];
			int tmpCnt = 0;

			while (1) {

				ny += dy[i];
				nx += dx[i];
				tmpCnt++;

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
					break;
				}

				if (map[ny][nx] == 0)
					continue;

				if (tmpCnt > cnt[y][x]) {
					// tmpCnt와 cnt[ny][nx]중 작은값
					if (tmpCnt < cnt[ny][nx]) {
						cnt[ny][nx] = tmpCnt;
						q.push({ ny, nx });
						
					}
				}
				else {
					// cnt[ny][nx]와 cnt[y][x]중 작은값
					if (cnt[ny][nx] > cnt[y][x]) {
						cnt[ny][nx] = cnt[y][x];
						q.push({ ny, nx });
					}
				}
				break;

			}
		}

		// 좌 우
		for (int i = 2; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (map[ny][nx] == 0)
				continue;

			if (cnt[ny][nx] > cnt[y][x]) {
				cnt[ny][nx] = cnt[y][x];
				q.push({ ny, nx });
			}
			
		}
	}
	
}

void solution() {
	bfs(snowman.first, snowman.second);

	cout << cnt[bell.first][bell.second];
		
}

int main() { 
	input();

	solution();
}