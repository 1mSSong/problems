#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;

p a; // 출발지
p b; // 목적지

int map[201][201];
vector <vector<int>> visited;

int to1;
int direct;

int dy[4] = { -1, 1, 0 , 0 };
int dx[4] = { 0, 0, -1, 1 };


void input() {
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;

	a.first += 100;
	a.second += 100;
	b.first += 100;
	b.second += 100;


	visited.assign(201, vector<int>(201, 21e8));
	p sub[4];

	for (int i = 0; i < 4; ++i) {
		cin >> sub[i].first >> sub[i].second;
		sub[i].first += 100;
		sub[i].second += 100;

	}

	// 출발, 도착지
	map[a.first][a.second] = 2;
	map[b.first][b.second] = 2;

	// 지하철 선 1로 setting
	for (int i = sub[0].first; i <= sub[1].first; ++i) {
		int y1 = sub[0].second;
		int y2 = sub[2].second;

		map[i][y1] = 1;
		map[i][y2] = 1;
	}

	for (int i = sub[0].second; i <= sub[3].second; ++i) {
		int x1 = sub[0].first;
		int x2 = sub[1].first;

		map[x1][i] = 1;
		map[x2][i] = 1;
	}
}


int bfs(p start) {
	queue<p> q;
	q.push(start);

	visited[start.first][start.second] = 0;


	while (!q.empty()) {
		p now = q.front();
		q.pop();

		if (map[now.first][now.second] == 1) {
			return visited[now.first][now.second];
		}

		for (int i = 0; i < 4; ++i) {
			int ny = now.second + dy[i];
			int nx = now.first + dx[i];

			if (ny < 0 || nx < 0 || ny >= 201 || nx >= 201)
				continue;

			if (visited[nx][ny] != 21e8)
				continue;


			visited[nx][ny] = visited[now.first][now.second] + 1;
			q.push({ nx, ny });
		}
	}

}

void solution() {
	direct = abs(a.first - b.first) + abs(a.second - b.second);
	
	
	to1 += bfs(a);
	if (to1 == 21e8)
		return;
	
	to1 += bfs(b);
}

int main() {
	input();

	solution();

	cout << min(to1, direct);
	

}