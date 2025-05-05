#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;

void input() {
	cin >> n;
	map.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
}

void dfs(int level, int y, int x) {
	int flag = 0; // 동일여부 확인
	for (int i = y; i < y + level; ++i) {
		for (int j = x; j < x + level; ++j) {
			if (map[y][x] != map[i][j]) {
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}

	// 모두 동일
	if (!flag) {
		cout << map[y][x];
		return;
	}

	cout << "(";

	if (level == 1) {
		cout << map[y][x];
		return;
	}

	dfs(level / 2, y, x);
	dfs(level / 2, y, x + level / 2);
	dfs(level / 2, y + level / 2, x);
	dfs(level / 2, y + level / 2, x + level / 2);
	
	cout << ")";
}


int main() {
	input();
	dfs(n, 0, 0);
}