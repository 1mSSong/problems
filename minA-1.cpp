#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;
int n, m;
int cnt = 0;
int d = 0; // 방향

vector<vector<int>> map;
vector <pair<int, int>> apple;

// 우회전
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void init() {
	map.clear();
	apple.clear();

	m = 0;
	d = 0;
	cnt = 0;

}

void input() {
	cin >> n;

	map.assign(n, vector<int>(n, 0));
	apple.resize(11);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];

			if (map[i][j] != 0) {
				apple[map[i][j]] = { i, j };
				m++;
			}
		}
	}
}


void solution(pair<int, int> s, pair<int, int> e) {
	// 지금 위치, 다음 사과의 단위방향
	int y = (e.first - s.first) / abs(e.first - s.first);
	int x = (e.second - s.second) / abs(e.second - s.second);

	int tmp[2] = { 1, 1 };
	while (1) {


		if (tmp[0] != 0) {
			if (dy[d] == y)
				tmp[0] = 0;
		}
		if (tmp[1] != 0) {
			if (dx[d] == x)
				tmp[1] = 0;
		}
		if (tmp[0] == 0 && tmp[1] == 0)
			break;

		cnt++;
		d = (d + 1) % 4;
	}

}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();


		for (int i = 0; i < m; ++i) {

			solution(apple[i], apple[i + 1]);
		}

		cout << "#" << tc << " " << cnt << "\n";
	}
}
