#include <iostream>
#include <vector>
using namespace std;

int n, l, r;
vector<vector<int>> person;
vector<vector<int>> map; // 그룹 정보
vector<vector<int>> prev_person; // while문 종료 정보

int group = 1;
int answer;

vector<int> sum;
vector<int> cnt;
int now_sum, now_cnt;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> n >> l >> r;

	person.resize(n, vector<int>(n, 0));
	map.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> person[i][j];
		}
	}
}

void dfs(int y, int x) {

	map[y][x] = group;
	now_cnt++;
	now_sum += person[y][x];

	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;

		if (map[ny][nx] != 0)
			continue;
		
		int diff = abs(person[y][x] - person[ny][nx]);
		if (diff > r || diff < l)
			continue;

		dfs(ny, nx);
	}
}


void movePerson() {

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

			if (map[i][j] != 0)
				continue;

			now_cnt = 0;
			now_sum = 0;
			dfs(i, j);

			sum.push_back(now_sum);
			cnt.push_back(now_cnt);
			group++;
		}
	}

	
}

void solution() {
	while (1) {

		group = 1;
		sum.clear();
		cnt.clear();

		map.clear();
		map.resize(n, vector<int>(n, 0));
		
		prev_person = person;
	
		movePerson();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {

				int now = map[i][j] - 1;
				person[i][j] = sum[now] / cnt[now];
			}
		}

		if (person == prev_person)
			break;
		
		answer++;
	}

	cout << answer;
}

int main() {
	input();

	solution();
}