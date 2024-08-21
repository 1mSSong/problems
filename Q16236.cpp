#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Fish {
	int y;
	int x;
	int d; //  거리

	bool operator< (Fish right) const {
		if (d < right.d) return false;
		if (d > right.d) return true;

		if (y < right.y) return false;
		if (y > right.y) return true;

		if(x < right.x) return false;
		if (x > right.x) return true;

		return false;
	}
};


int n;

vector<vector<int>> map;
pair<int, int> shark;
vector<vector<int>> visited[2]; // 거리, fish check 여부
vector<vector<int>> fishCheck;
priority_queue<Fish> fish; // 먹을 수 있는 물고기


int nowSize = 2; // 현재 상어 크기
int cnt; // 먹은 물고기 개수
int time; // 걸린 시간

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> n;

	map.assign(n, vector<int>(n, 0));
	visited[0].assign(n, vector<int>(n, 2e9));
	visited[1].assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				shark = { i, j };
			}
		}
	}
}

bool bfs(int sy, int sx) {
	queue<pair<int, int>> q;
	
	q.push({ sy, sx });
	visited[0][sy][sx] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			if (map[ny][nx] > nowSize)
				continue;

			if (visited[0][ny][nx] <= visited[0][y][x] + 1)
				continue;

			visited[0][ny][nx] = visited[0][y][x] + 1;
			q.push({ ny, nx });

			if (map[ny][nx] == 0)
				continue;

			if (map[ny][nx] < nowSize && visited[1][ny][nx] == 0) {
				fish.push({ ny, nx, visited[0][ny][nx] });
				visited[1][ny][nx] = 1;
			}

		}
	}

	return (!fish.empty());
}

void solution() {
	while (1) {
		visited[0].clear();
		visited[1].clear();
		
		while (!fish.empty()) {
			fish.pop();
		}

		visited[0].assign(n, vector<int>(n, 2e9));
		visited[1].assign(n, vector<int>(n, 0));
		
		// 더 이상 물고기 X
		if (!bfs(shark.first, shark.second)) {
			cout << time;
			return;
		}

		map[shark.first][shark.second] = 0;
		
		shark = { fish.top().y, fish.top().x };
		map[shark.first][shark.second] = 9;

		time += fish.top().d;
		cnt++;
		
		if (cnt == nowSize) {
			cnt = 0;
			nowSize++;
		}
			
	}
}

int main() {
	input();
	
	solution();
}