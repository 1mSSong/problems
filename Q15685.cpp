#include <iostream>
#include <vector>
using namespace std;

struct coord{
	int sy, sx;
	int ey, ex;
	int dir;
};

int n;
int res;

int map[200][200]; // 꼭짓점 카운트
vector<coord> arr[20];
int gen[20]; // 세대

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };


void input() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b, d;
		int g;

		cin >> a >> b >> d >> g;

		gen[i] = g;

		int ny = b + dy[d];
		int nx = a + dx[d];

		arr[i].push_back({ b, a, ny, nx, d });
		
		map[b][a] = 1;
		map[ny][nx] = 1;
		
	}
}


void create_curve(int i) {
	

	int sizes = arr[i].size();
	for (int j = sizes - 1; j >= 0; --j) {
		// 마지막 선분
		coord last = arr[i][arr[i].size() - 1];
		int dir = arr[i][j].dir;

		int sy = last.ey;
		int sx = last.ex;

		int d = (dir + 1) % 4;
		int ey = sy + dy[d];
		int ex = sx + dx[d];
		
		coord now = { sy, sx, ey, ex, d };
		arr[i].push_back(now);

		map[ey][ex] = 1;

	}
}

void solution() {
	
	for (int i = 0; i < n; ++i) {
		// 세대만큼
		for (int j = 0; j < gen[i]; ++j) {
			create_curve(i);
		}
	}

	for (int i = 0; i < 200; ++i) {
		for (int j = 0; j < 200; ++j) {
			if (map[i][j] == 1 && map[i][j + 1] == 1 &&
				map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
				res++;
		}
	}
}

int main() {
	input();

	solution();

	cout << res;
}