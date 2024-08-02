#include <iostream>
#include <vector>
using namespace std;

int r, c;
int cnt = 1;
int maxcnt = 0;

vector<vector<pair<char, int>>> arr;
int dat[26];
int  dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> r >> c;

	arr.resize(r);

	for (int i = 0; i < r; ++i) {
		arr[i].resize(c);
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			char tmp;
			cin >> tmp;

			arr[i][j] = { tmp, 0 };
		}
	}
}

void dfs(int y, int x) {
	arr[y][x].second = 1;
	dat[arr[y][x].first - 'A'] = 1;

	

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c)
			continue;

		if (dat[arr[ny][nx].first - 'A'] != 0) continue;

		if (arr[ny][nx].second == 1)
			continue;

		cnt++;
		dat[arr[ny][nx].first - 'A'] = 1;
		arr[ny][nx].second = 1;

		dfs(ny, nx);

		arr[ny][nx].second = 0;
		dat[arr[ny][nx].first - 'A'] = 0;
		cnt--;

	}

	if (cnt > maxcnt) {
		maxcnt = cnt;
	}
	
}

int main() {
	input();

	dfs(0, 0);

	cout << maxcnt;
}