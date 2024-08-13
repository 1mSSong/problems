#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int n, m;
int ans;
int sum;

vector<vector<int>> map;
vector<vector<int>> visited;
int path[5][2];

// x : 짝수
int dy1[6] = { -1, -1, -1, 0, 0, 1 };
// x : 홀수
int dy2[6] = { 1, 1, 1, 0, 0, -1 };
int dx[6] = { -1, 0, 1, -1, 1, 0 };


void init() {
	map.clear();
	visited.clear();

	ans = 0;
	sum = 0;
}

void input() {
	cin >> n >> m;

	map.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
}


void dfs(int y, int x, int now) {

	if (now >= 3) {
		
		ans = max(sum, ans);

		return;
	}

	for (int i = 0; i < 6; ++i) {
		int ny = y;
		if (x % 2 == 0) {
			ny += dy1[i];
		}
		else {
			ny += dy2[i];
		}
		int nx = x + dx[i];

		if (ny >= n || nx >= m || ny < 0 || nx < 0)
			continue;

		if (visited[ny][nx] == 1)
			continue;

		path[now + 1][0] = ny;
		path[now + 1][1] = nx;
		sum += map[ny][nx];
		visited[ny][nx] = 1;

		dfs(ny, nx, now + 1);

		sum -= map[ny][nx];
		visited[ny][nx] = 0;
	}
}

void func(int y, int x) {
	vector<int> arr;

	int tmp = 0;

	if (x % 2 == 0) {
		for (int i = 0; i < 6; ++i) {
			int ny = y + dy1[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			arr.push_back(map[ny][nx]);
		}
	}
	else {
		for (int i = 0; i < 6; ++i) {
			int ny = y + dy2[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			arr.push_back(map[ny][nx]);
		}
	}
	if (arr.size() < 3)
		return;

	sort(arr.begin(), arr.end(), greater<>());

	for (int i = 0; i < 3; ++i) {
		tmp += arr[i];
	}

	tmp += map[y][x];
	ans = max(tmp, ans);
}

//void func(int y, int x) {
//	int tmpsum1 = 0;
//	int tmpsum2 = 0;
//
//	if (x % 2 == 0) {
//		if (y - 1 < 0)
//			return;
//		if (x + 1 >= m)
//			return;
//		if (x - 1 < 0)
//			return;
//
//		// 짝수
//		// 뒤집어진 Y 모양
//		tmpsum2 += map[y][x];
//		tmpsum2 += map[y - 1][x];
//		tmpsum2 += map[y][x - 1];
//		tmpsum2 += map[y][x + 1];
//
//
//		if (y + 1 >= n)
//			return;
//
//		// Y 모양
//		tmpsum1 += map[y][x];
//		tmpsum1 += map[y - 1][x - 1];
//		tmpsum1 += map[y - 1][x + 1];
//		tmpsum1 += map[y + 1][x];
//
//	}
//	else {
//		
//		if (x + 1 >= m)
//			return;
//		if (y + 1 >= n)
//			return;
//		if (x - 1 < 0)
//			return;
//
//		// 홀수
//		// Y 모양
//		tmpsum1 += map[y][x];
//		tmpsum1 += map[y][x - 1];
//		tmpsum1 += map[y][x + 1];
//		tmpsum1 += map[y + 1][x];
//
//		if (y - 1 < 0)
//			return;
//
//		// 뒤집어진 Y 모양
//		tmpsum2 += map[y][x];
//		tmpsum2 += map[y - 1][x];
//		tmpsum2 += map[y + 1][x - 1];
//		tmpsum2 += map[y + 1][x + 1];
//	}
//
//	ans = max(max(tmpsum1, tmpsum2), ans);
//}

void solution() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sum = map[i][j];
			visited[i][j] = 1;
			path[0][0] = i;
			path[0][1] = j;

			dfs(i, j, 0);

			visited[i][j] = 0;

			func(i, j);
		}
	}
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		solution();

		cout << "#" << tc << " " << ans << "\n";
	}

}