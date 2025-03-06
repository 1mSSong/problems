#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int answer = 21e8;

//vector<vector<int>> map;
int map[1001][1001];
int visited[2][1001][1001];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct coord {
	int y;
	int x;
	int chk;
};

void input() {
	cin >> n >> m;
	
	//map.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
}

void bfs() {
	
	//vector<vector<vector<int>>> visited;
	//visited.resize(2, vector<vector<int>>(n, vector<int>(m, 0)));

	queue<coord> q;
	q.push({ 0, 0, 0});
	visited[0][0][0] = 1;

	while (!q.empty()) {

		int y = q.front().y;
		int x = q.front().x;
		int chk = q.front().chk;
		q.pop();

		if (y == n - 1 && x == m - 1)
			break;


		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			// ���� ��
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// �̹� �湮
			if (visited[chk][ny][nx] != 0)
				continue;

			// ���� �� -> �μ��� ����
			if (map[ny][nx]) {

				// �̹� ���� �μ�
				if (chk) {
					continue;
				}
				
				// ���� �μ� �� ����
				visited[1][ny][nx] = visited[0][y][x] + 1;
				q.push({ ny, nx, 1 });
			}

			// ���� �ƴ� -> �׳� ��������
			else {
				visited[chk][ny][nx] = visited[chk][y][x] + 1;
				q.push({ ny, nx, chk });
			}
		}
	}

	for (int i = 0; i < 2; ++i) {
		if (visited[i][n - 1][m - 1] == 0)
			continue;

		answer = min(answer, visited[i][n - 1][m - 1]);
	}

}

void solution() {

	bfs();

	if (answer == 21e8)
		answer = -1;

	cout << answer;
}

int main() {

	input();

	solution();
}