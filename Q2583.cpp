#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;


int n, m;
int k;

vector<vector<int>> map;
vector<int> answer;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> m >> n >> k;
	
	map.resize(m , vector<int>(n));

}

void makeSquare() {

	for (int i = 0; i < k; ++i) {
		pii start, finish;

		cin >> start.first >> start.second;
		cin >> finish.first >> finish.second;

		for (int i = start.second; i < finish.second; ++i) {
			for (int j = start.first; j < finish.first; ++j) {
				map[i][j] = 1;
			}
		}

	}
	
}

void bfs(int y, int x) {

	queue<pii> q;

	q.push({ y, x });
	int now_size = 1;
	map[y][x] = 1;
	
	while (!q.empty()) {

		pii now = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];


			if (ny < 0 || nx < 0 || ny >= m || nx >= n)
				continue;

			if (map[ny][nx])
				continue;

			now_size++;

			q.push({ ny, nx });
			map[ny][nx] = 1;
		}
	}

	answer.push_back(now_size);
}

void solution() {
	
	makeSquare();

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {

			if (map[i][j])
				continue;

			bfs(i, j);
		}
	}

	cout << answer.size() << "\n";

	sort(answer.begin(), answer.end());

	for (auto item : answer) {
		cout << item << " ";
	}

}

int main() {

	input();

	solution();
}