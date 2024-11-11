#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<vector<int>> map;
vector<vector<int>> visited;

int answer;

int sum;


int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int shape1[2][3][2] = {
	{
		{1, 0}, {1, 1}, {1, 0}
	},

	{
		{0, 1}, {1, 1}, {0, 1}
	}
};
 
int shape2[2][2][3] = {
	{
		{0, 1, 0}, {1, 1, 1}
	},

	{
		{1, 1, 1}, {0, 1, 0}
	}
};

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


void dfs(int y, int x, int level) {
	
	if (level == 3) {

		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;

		if (visited[ny][nx])
			continue;

		visited[ny][nx] = 1;
		sum += map[ny][nx];

		dfs(ny, nx, level + 1);

		visited[ny][nx] = 0;
		sum -= map[ny][nx];
	}

}


void solution() {
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = 1;
			sum = map[i][j];

			dfs(i, j, 0);

			visited[i][j] = 0;
			sum = 0;
		}
	}

	// で ぬ っ た 乞丞

	// た / っ
	for (int i = 0; i <= n - 3; ++i) {
		for (int j = 0; j <= m - 2; ++j) {

			for (int k = 0; k < 2; ++k) {

				int tmp = 0;

				for (int r = 0; r < 3; ++r) {
					for (int c = 0; c < 2; ++c) {
						tmp += shape1[k][r][c] * map[i + r][j + c];
					}
				}

				answer = max(answer, tmp);
			}

		}
	}

	// で / ぬ
	for (int i = 0; i <= n - 2; ++i) {
		for (int j = 0; j <= m - 3; ++j) {

			

			for (int k = 0; k < 2; ++k) {

				int tmp = 0;

				for (int r = 0; r < 2; ++r) {
					for (int c = 0; c < 3; ++c) {
						tmp += shape2[k][r][c] * map[i + r][j + c];
					}
				}

				answer = max(answer, tmp);
			}

		}
	}

}

int main() {

	input();
	
	solution();

	cout << answer;
}