#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[201][201];

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우)
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		
		// 현재 위치에서 4가지 방향으로 위치 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 미로 공간을 벗어난 경우 무시
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			//벽인 경우 무시
			if (map[nx][ny] == 0)
				continue;

			// 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
			if (map[nx][ny] == 1) {
				map[nx][ny] = map[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return map[n - 1][m - 1];
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	cout << bfs(0, 0);
}