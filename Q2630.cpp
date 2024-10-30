#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;

int answer[2];

void input() {
	cin >> n;
	
	map.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
}

bool chk(int level, int r, int c) {
	int index = map[r][c];

	for (int i = 0; i < level; ++i) {
		for (int j = 0; j < level; ++j) {
			if (map[r + i][c + j] != index)
				return false;
		}
	}

	return true;
}

void dfs(int level, int r, int c) {

	// 다 같은 색
	if (chk(level, r, c)) {
		answer[map[r][c]]++;
		return;
	}
	
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			dfs(level / 2, r + level * i / 2, c + level * j / 2);
		}
	}
}


int main() {
	input();

	dfs(n, 0, 0);

	cout << answer[0] << "\n" << answer[1];
}