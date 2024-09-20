#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;


int n, m, k, c;

vector<vector<int>> map;
vector<vector<int>> remDie; // 남아있는 제초제 년수
vector<vector<int>> upTree; // 번식할 나무

p now; // 제초제를 뿌릴 위치
int max_die; // 제초제를 뿌렸을 때 가장 많이 죽는 나무의 수 

int ans;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int dcy[4] = { -1, -1, 1, 1 };
int dcx[4] = { -1, 1, -1, 1 };


void input() {
	cin >> n >> m >> k >> c;

	map.assign(n, vector<int>(n, 0));
	remDie.assign(n, vector<int>(n, 0));;
	upTree.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
}

// 나무 성장
void growTree() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

			if (map[i][j] <= 0)
				continue;

			int cnt = 0; // 인접한 나무 개수

			for (int d = 0; d < 4; ++d) {
				int ny = i + dy[d];
				int nx = j + dx[d];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
					continue;

				if (map[ny][nx] == -1)
					continue;

				if (map[ny][nx] != 0)
					cnt++;
			}

			map[i][j] += cnt;
		}
	}
}

void addTree() {

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

			if (map[i][j] <= 0)
				continue;

			int arr[4] = { 0, 0, 0, 0 }; // 번식 가능한 위치 (상 하 좌 우)
			int cnt = 0; // 번식 가능한 위치 개수

			for (int d = 0; d < 4; ++d) {
				int ny = i + dy[d];
				int nx = j + dx[d];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
					continue;

				// 번식 불가
				if (map[ny][nx] == -1 || map[ny][nx] > 0 || remDie[ny][nx] != 0)
					continue;

				// 번식 가능
				arr[d] = 1;
				cnt++;
			}

			if (cnt == 0)
				continue;

			for (int d = 0; d < 4; ++d) {

				if (arr[d] == 0)
					continue;

				int ny = i + dy[d];
				int nx = j + dx[d];

				upTree[ny][nx] += (map[i][j] / cnt);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			map[i][j] += upTree[i][j];
			upTree[i][j] = 0;
		}
	}
}

void reduceDie() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int tmp = remDie[i][j] - 1;

			(tmp <= 0) ? tmp = 0 : 1;

			remDie[i][j] = tmp;
		}
	}
}

// 제초제 뿌릴 위치 고르기
void chooseCoord() {

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

			if (map[i][j] <= 0)
				continue;

			int tmp = map[i][j];

			for (int d = 0; d < 4; ++d) {
				for (int a = 1; a <= k; ++a) {
					int ny = i + dcy[d] * a;
					int nx = j + dcx[d] * a;

					if (ny < 0 || nx < 0 || ny >= n || nx >= n)
						break;

					if (map[ny][nx] <= 0 || remDie[ny][nx] > 0)
						break;


					// 박멸 가능
					tmp += map[ny][nx];

				}
			}


			if (max_die < tmp) {
				max_die = tmp;
				now = { i, j };
			}
		}
	}


	//cout << "---제초제 위치 ---: " << now.first << " " << now.second << "\n\n";

}

void dieTree() {
	ans += max_die;
	max_die = 0;

	remDie[now.first][now.second] = c;
	map[now.first][now.second] = 0;


	for (int d = 0; d < 4; ++d) {
		for (int a = 1; a <= k; ++a) {
			int ny = now.first + dcy[d] * a;
			int nx = now.second + dcx[d] * a;

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				break;

			if (map[ny][nx] == -1)
				break;

			if (map[ny][nx] <= 0 || remDie[ny][nx] > 0) {
				remDie[ny][nx] = c;
				break;
			}

			remDie[ny][nx] = max(remDie[ny][nx], c);
			map[ny][nx] = 0;

		}
	}
}

void solution() {
	// 나무 성장
	growTree();

	// 나무 번식
	addTree();

	/*cout << "----나무번식----\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";*/

	// 제초제 줄이기
	reduceDie();


	// 제초제 줄 위치 고르기

	chooseCoord();

	// 박멸
	dieTree();

	/*cout << "----남아있는 제초제----\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << remDie[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";

	cout << "----나무 현재 상태 ---\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";


	cout << "-----여기까지 정답---- : " << ans << "\n";*/

}

int main() {
	input();

	for (int i = 0; i < m; ++i) {
		solution();
	}
	cout << ans;
}