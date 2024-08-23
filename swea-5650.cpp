#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int n;

int score; // Á¡¼ö
int sum;

vector<vector<int>> map; // -1: ºí·¢È¦, 0: ºó°ø°£, 1 ~ 5: ºí·Ï, 6 ~ 10: ¿úÈ¦
int hole[5][4];

// »ó, ÁÂ, ÇÏ, ¿ì
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int dir = 0;


void init() {
	map.clear();

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4; ++j) {
			hole[i][j] = -1;
		}
	}

	score = 0;
	sum = 0;
	dir = 0;
}

void input() {
	cin >> n;

	map.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];

			if (map[i][j] >= 6) {

				int index = map[i][j] - 6;

				if (hole[index][0] == -1 && hole[index][1] == -1) {

					hole[index][0] = i;
					hole[index][1] = j;
				}
				else {

					hole[index][2] = i;
					hole[index][3] = j;
				}
			}
		}
	}
}

void solution(int y, int x) {

	int ny = y;
	int nx = x;

	while (1) {

		ny += dy[dir];
		nx += dx[dir];

		// ¹üÀ§ ¹Û
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
			dir = (dir + 2) % 4;
			sum++;
			continue;
		}

		// ³¡³ª´Â Á¶°Ç
		if (map[ny][nx] == -1 || (ny == y && nx == x)) {
			score = max(score, sum);
			break;
		}


		// ºó °ø°£
		if (map[ny][nx] == 0)
			continue;

		
		// ¿ú È¦ ÀÏ ¶§
		if (map[ny][nx] > 5) {
			int index = map[ny][nx] - 6;

			if (hole[index][0] == ny && hole[index][1] == nx) {
				ny = hole[index][2];
				nx = hole[index][3];
			}

			else if (hole[index][2] == ny && hole[index][3] == nx) {
				ny = hole[index][0];
				nx = hole[index][1];
			}
			continue;
		}

		// ºí·ÏÀÏ ¶§
		if (map[ny][nx] == 5) {
			dir = (dir + 2) % 4;
			sum++;
		}

		else if (map[ny][nx] == 1) {
			if (dir == 0 || dir == 3) {
				dir = (dir + 2) % 4;
				sum++;
			}
			else if (dir == 1) {
				dir = 0;
				sum++;
			}
			else if (dir == 2) {
				dir = 3;
				sum++;
			}
		}

		else if (map[ny][nx] == 2) {
			if (dir == 2 || dir == 3) {
				dir = (dir + 2) % 4;
				sum++;
			}
			else if (dir == 0) {
				dir = 3;
				sum++;
			}
			else if (dir == 1) {
				dir = 2;
				sum++;
			}
		}

		else if (map[ny][nx] == 3) {
			if (dir == 2 || dir == 1) {
				dir = (dir + 2) % 4;
				sum++;
			}
			else if (dir == 0) {
				dir = 1;
				sum++;
			}
			else if (dir == 3) {
				dir = 2;
				sum++;
			}
		}

		else if (map[ny][nx] == 4) {
			if (dir ==  0|| dir == 1) {
				dir = (dir + 2) % 4;
				sum++;
			}
			else if (dir == 2) {
				dir = 1;
				sum++;
			}
			else if (dir == 3) {
				dir = 0;
				sum++;
			}
		}
	}
	
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j] == 0) {
					
					for (int d = 0; d < 4; ++d) {
						dir = d;
						sum = 0;
						solution(i, j);
					}
				}
			}
		}

		cout << "#" << tc << " " << score << "\n";
	}
}