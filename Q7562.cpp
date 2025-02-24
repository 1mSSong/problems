#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int T;

int l;
vector<vector<int>> map; // value: 최소 이동 횟수

pii start, finish;

int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };

void init() {
	map.clear();
}

void input() {

	cin >> l;

	map.resize(l, vector<int>(l, 21e8));

	cin >> start.first >> start.second;
	cin >> finish.first >> finish.second;
}

void bfs() {

	queue<pii> q;

	q.push(start);
	map[start.first][start.second] = 0;

	if (start == finish)
		return;

	while (!q.empty()) {
		pii now = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= l || nx >= l)
				continue;

			if (map[ny][nx] != 21e8)
				continue;

			map[ny][nx] = map[now.first][now.second] + 1;
			q.push({ ny, nx });

			if (ny == finish.first && nx == finish.second)
				return;
		}
	}
}

void solution() {

	bfs();

	cout << map[finish.first][finish.second] << "\n";
}

int main() {

	cin >> T;

	for (int i = 0; i < T; ++i) {

		init();

		input();

		solution();
	}
}