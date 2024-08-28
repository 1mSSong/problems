#include <iostream>
#include <vector>
using namespace std;

int t;
int n;

int res[2];

vector<vector<int>> map;

void init() {
	map.clear();

	res[0] = 0;
	res[1] = 0;
}

void input() {
	cin >> n;

	map.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
}

void down_block(int col) {
	double now_force = 1;
	int now_location = 0;
	int now_size = 1;


	double next_force = -1;
	int next_location = -1;
	int next_size = 0;

	while (1) {
		if (now_location >= n)
			break;

		// 다음 블록 찾기
		for (int i = now_location + 1; i < n; ++i) {
			if (map[i][col] == 1)
				break;

			now_force = now_force * 1.9;
			now_location = i;
			
		}

		// 바닥에 도착한 경우
		if (now_location == n - 1) {
			break;
		}

		// 새로운 블록을 만났을 때
		next_force = 0;
		next_location = now_location;
		next_size = 0;

		// 새로운 블록 크기 찾기
		for (int j = now_location + 1; j < n; ++j) {
			 
			if (map[j][col] == 0) {
				break;
			}

			next_location = j;
			next_force++;
			next_size++;
		}

		// 새로운 블록 찾지 못함
		if (now_location == next_location)
			break;

		// 더 이상 하강 불가능
		if (now_force <= next_force)
			break;

		// 합치기
		now_force += next_force;
		now_location = next_location;
		now_size += next_size;

		next_location = -1;
		next_force = -1;
		next_size = 0;
	}

	// 위치 업데이트
	
	for (int i = 0; i < now_location; ++i) {
		map[i][col] = 0;
	}

	for (int i = 0; i < now_size; ++i) {
		map[now_location - i][col] = 1;
	}
}

void right_block(int row) {
	double now_force = 1;
	int now_location = 0;
	int now_size = 1;


	double next_force = -1;
	int next_location = -1;
	int next_size = 0;

	while (1) {
		if (now_location >= n)
			break;

		// 다음 블록 찾기
		for (int i = now_location + 1; i < n; ++i) {
			if (map[row][i] == 1)
				break;

			now_force = now_force * 1.9;
			now_location = i;

		}

		// 바닥에 도착한 경우
		if (now_location == n - 1) {
			break;
		}

		// 새로운 블록을 만났을 때
		next_force = 0;
		next_location = now_location;
		next_size = 0;

		// 새로운 블록 크기 찾기
		for (int j = now_location + 1; j < n; ++j) {

			if (map[row][j] == 0) {
				break;
			}

			next_location = j;
			next_force++;
			next_size++;
		}

		// 새로운 블록 찾지 못함
		if (now_location == next_location)
			break;

		// 더 이상 하강 불가능
		if (now_force <= next_force)
			break;

		// 합치기
		now_force += next_force;
		now_location = next_location;
		now_size += next_size;

		next_location = -1;
		next_force = -1;
		next_size = 0;
	}

	// 위치 업데이트

	for (int i = 0; i < now_location; ++i) {
		map[row][i] = 0;
	}

	for (int i = 0; i < now_size; ++i) {
		map[row][now_location - i] = 1;
	}

}

void solution() {
	
	// 하강
	for (int i = 0; i < n; ++i) {
		if (map[0][i] == 0)
			continue;

		down_block(i);
	}

	// 우측 하강
	for (int i = 0; i < n; ++i) {
		if (map[i][0] == 0)
			continue;

		right_block(i);
	}
	
	for (int i = 0; i < n; ++i) {
		if (map[i][n - 1] == 1)
			res[1]++;

		if (map[n - 1][i] == 1)
			res[0]++;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		solution();

		cout << "#" << tc << " " << res[0] << " " << res[1] << "\n";
	}
}
