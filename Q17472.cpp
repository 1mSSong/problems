#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Bridge {
	int s, e;
	int cost;

	bool operator < (Bridge right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;

		return false;
	}
};

int n, m;
int group = 2;
int res; // 최소 cost

int parent[10];

vector<vector<int>> map;
vector<vector<int>> visited;

priority_queue<Bridge> bridges;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


void input() {
	cin >> n >> m;
	
	map.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 7; ++i) {
		parent[i] = i;
	}
}

void dfs(int y, int x) {
	visited[y][x] = 1;
	map[y][x] = group;

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;

		if (map[ny][nx] == 0)
			continue;

		if (visited[ny][nx] == 1)
			continue;

		map[ny][nx] = group;
		visited[ny][nx] = 1;
		
		dfs(ny, nx);
	}
}

void make_group() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				dfs(i, j);

				group++;
			}
		}
	}
}


void make_bridge(int y, int x, int d) {
	int ny = y;
	int nx = x;
	
	while (1) {
		ny += dy[d];
		nx += dx[d];

		// 범위 밖
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			break;

		// 바다가 아닌 경우 (아직도 섬)
		if (map[ny][nx] == map[y][x])
			break;

		// 다른 섬에 도착한 경우
		if (map[ny][nx] > 0 && map[ny][nx] != map[y][x]) {
			int cost = abs(ny - y) + abs(nx - x) - 1;
			
			if (cost > 1)
				bridges.push({ map[y][x], map[ny][nx], cost });

			break;
		}
	}
}

void calc_dist(int y, int x) {
	visited[y][x] = 1;

	for (int j = 0; j < 4; ++j) {
		make_bridge(y, x, j);
	}

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;


		if (visited[ny][nx] == 1)
			continue;

		if (map[ny][nx] == 0) {

		}
			continue;

		calc_dist(ny, nx);
	}
}


void solution() {
	// 섬 구분하기
	make_group();

	visited.clear();
	visited.assign(n, vector<int>(m, 0));

	// 다리 그리기

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] != 0 && visited[i][j] == 0) {
				calc_dist(i, j);
			}
		}
	}

}

int Find(int a) {
	if (a == parent[a])
		return a;

	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB)
		return;

	parent[rootB] = rootA;
}

void mst() {

	// group 개수
	group -= 2;

	// 다리 개수
	int cnt = 0;

	while (!bridges.empty()) {
		if (cnt == group - 1)
			break;

		Bridge now = bridges.top();
		bridges.pop();

		int rootA = Find(now.s);
		int rootB = Find(now.e);

		if (rootA == rootB)
			continue;

		cnt++;
		Union(rootA, rootB);
		res += now.cost;
	}

	if (cnt < group - 1)
		res = -1;

}

int main() {
	input();

	solution();
	
	mst();

	cout << res;
}