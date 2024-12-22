#include <iostream>
#include <vector>
using namespace std;

int n;

vector<vector<int>> map;
vector<int> dat; // 그룹에 속해있는지

int answer = 21e8;

void input() {
	
	cin >> n;

	map.assign(n, vector<int>(n, 0));
	dat.resize(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

			cin >> map[i][j];

		}
	}
}

void calSum() {

	int sum[2] = { 0, 0 };

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

			if (i == j)
				continue;

			if (dat[i] == 1 && dat[j] == 1) {
				sum[0] += map[i][j];
			}

			if (dat[i] == 0 && dat[j] == 0) {
				sum[1] += map[i][j];
			}
		}
	}

	answer = min(answer, abs(sum[0] - sum[1]));
}

void dfs(int now, int idx) {
	
	if (now == n / 2 ) {

		calSum();

		return;
	}
	
	for (int i = idx; i < n; ++i) {
		
		dat[i] = 1;

		dfs(now + 1, i + 1);

		dat[i] = 0;
	}


}

void solution() {
	// 중복 방지 dat[0] = 1;
	dat[0] = 1;

	dfs(1, 1);

	cout << answer;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();

	solution();
}