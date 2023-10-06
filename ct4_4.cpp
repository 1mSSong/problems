#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, d;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void turn_left() {
	d--;
	if (d == -1) d = 3;
}

int main() {

	cin >> n >> m;
	cin >> x >> y >> d;

	vector<vector<int>> map;
	map.assign(n, vector<int> (m, 1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	map[x][y] = 1;

	int ans = 1;
	int turn_time = 0;

	while (1) {
		turn_left();

		int nx = x + dx[d];
		int ny = y + dx[d];

		// 회전한 이후 정면에 가보지 않은 칸이 존재하는 경우
		if (map[nx][ny] == 0) {
			map[nx][ny] = 1;
			x = nx;
			y = ny;
			ans++;
			turn_time = 0;
			continue;
		}

		// 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
		else
			turn_time++;

		// 네 방향 모두 갈 수 없는 경우
		if (turn_time == 4) {
			nx = x - dx[d];
			ny = y - dy[d];

			// 뒤로 갈 수 있다면 이동
			if (map[nx][ny] == 0) {
				x = nx;
				y = ny;
			}

			// 뒤로 바다가 막혀 있는 경우
			else break;
			turn_time = 0;
		}
	}
	cout << ans;
}