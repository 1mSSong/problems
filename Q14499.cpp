#include <iostream>
#include <vector>
using namespace std;

struct DiceInfo {
	int top;
	int right;
	int down;
};

int n, m;
int x, y;
int k;

int dice[8];
vector<vector<int>> map;

DiceInfo now_dice = { 1, 3, 5 };
DiceInfo next_dice = { 0, 0, 0 };

int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void moveDice(int dir) {
	
	if (dir == 1) {
		next_dice.top = 7 - now_dice.right;
		next_dice.right = now_dice.top;
		next_dice.down = now_dice.down;
	}
	else if (dir == 2) {
		next_dice.top = now_dice.right;
		next_dice.right = 7 - now_dice.top;
		next_dice.down = now_dice.down;
	}
	else if (dir == 3) {
		next_dice.top = now_dice.down;
		next_dice.right = now_dice.right;
		next_dice.down = 7 - now_dice.top;
	}
	else if (dir == 4) {
		next_dice.top = 7 - now_dice.down;
		next_dice.right = now_dice.right;
		next_dice.down = now_dice.top;
	}
	//cout << "----now----\n";
	//cout << now_dice.top << " " << now_dice.right << " " << now_dice.down << " \n";

	//cout << "----next----\n";
	//cout << next_dice.top << " " << next_dice.right << " " << next_dice.down << " \n";

	now_dice = next_dice;
}

void solution(int dir) {

	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || nx < 0 || ny >= n || nx >= m)
		return;
	
	moveDice(dir);

	if (map[ny][nx] == 0) {
		map[ny][nx] = dice[7 - now_dice.top];
	}
	else {
		dice[7 - now_dice.top] = map[ny][nx];
		map[ny][nx] = 0;
	}

	y = ny;
	x = nx;
	cout << dice[now_dice.top] << "\n";
}

void input() {

	cin >> n >> m;
	cin >> y >> x;
	cin >> k;

	map.resize(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; ++i) {
		int dir;
		cin >> dir;

		solution(dir);

	}
}

int main() {

	input();
}