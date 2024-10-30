#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int level;

int now_r, now_c;
int answer;
int flag;


bool chk(int level, int y, int x) {
	int y1[2] = { y + pow(2, level), y };
	int x1[2] = { x + pow(2, level), x };

	if (r >= y1[1] && r < y1[0] && c >= x1[1] && c < x1[0])
		return true;

	return false;
}

void input() {
	cin >> n >> r >> c;

	level = n;
	n = pow(2, n);
}

void dfs(int level, int now_r, int now_c) {

	if (flag)
		return;

	// 절대 없음
	if (!chk(level, now_r, now_c)) {
		answer += (pow(2, level) * pow(2, level));
		return;
	}


	if (level == 1) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (now_r + i == r && now_c + j == c) {
					cout << answer;
					flag = 1;
					return;
				}
				answer++;
			}
		}
	}
	
	int tmp = pow(2, level - 1);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (flag)
				break;
			dfs(level - 1, now_r + tmp * i, now_c + tmp * j);
		}
		if (flag)
			break;
	}
}

int main() {
	input();

	dfs(level, 0, 0);
}