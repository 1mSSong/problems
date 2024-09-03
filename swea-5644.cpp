#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct battery {
	int y, x;
	int c; // 충전 범위
	int p; // 성능

	bool operator < (battery right) const {
		if (p < right.p) return true;
		if (p > right.p) return false;

		return false;
	}
};


int t;
int m, a;

int res;

int map[10][10]; // battery 영향권
vector<battery> bc; // battery 정보 저장

pair<int, int> user1 = { 0, 0 };
pair<int, int> user2 = { 9, 9 };

vector<int> move1;
vector<int> move2;

int dy[5] = { 0, -1, 0, 1, 0 };
int dx[5] = { 0, 0, 1, 0, -1 };


void init() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			map[i][j] = 0;
		}
	}
	 
	bc.clear();

	user1 = { 0, 0 };
	user2 = { 9, 9 };

	move1.clear();
	move2.clear();

	res = 0;
}

void input() {
	cin >> m >> a;

	move1.resize(m + 1);
	move2.resize(m + 1);

	move1[0] = 0;
	move2[0] = 0;
	for (int i = 1; i <= m; ++i) {
		cin >> move1[i];
	}

	for (int i = 1; i <= m; ++i) {
		cin >> move2[i];
	}

	for (int i = 0; i < a; ++i) {
		int y, x, c, p;

		cin >> x >> y >> c >> p;

		bc.push_back({ y - 1, x - 1, c, p });
	}
}

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void chkBattery() {
	priority_queue<battery> bc1;
	priority_queue<battery> bc2;


	for (int i = 0; i < a; ++i) {
		if (dist(user1, { bc[i].y, bc[i].x }) <= bc[i].c)
			bc1.push(bc[i]);

		if (dist(user2, { bc[i].y, bc[i].x }) <= bc[i].c)
			bc2.push(bc[i]);
	}

	if (bc1.empty() && bc2.empty()) return;

	if (bc1.empty() && !bc2.empty()) {
		res += bc2.top().p;
		return;
	}

	if (!bc1.empty() && bc2.empty()) {
		res += bc1.top().p;
		return;
	}

	// 둘 다 하나 이상 존재

	// 최대가 다름
	if (!(bc1.top().y == bc2.top().y && bc1.top().x == bc2.top().x)) {
		res += bc1.top().p;
		res += bc2.top().p;
		return;
	}
	

	// 최대 동일
	battery  now = bc1.top();
	bc1.pop(); bc2.pop();

	if (bc1.empty() && bc2.empty()) {
		res += now.p;
		return;
	}

	if (bc1.empty() && !bc2.empty()) {
		res += now.p;
		res += bc2.top().p;
		return;
	}
	else if (!bc1.empty() && bc2.empty()) {
		res += now.p;
		res += bc1.top().p;
		return;
	}

	// 둘다 empty X
	res += now.p;
	res += max(bc1.top().p, bc2.top().p);
	

}

void solution() {
	
	for (int i = 0; i <= m; ++i) {
		user1.first += dy[move1[i]];
		user1.second += dx[move1[i]];

		user2.first += dy[move2[i]];
		user2.second += dx[move2[i]];

		chkBattery();
	}
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		solution();

		cout << "#" << tc << " " << res << "\n";
	}
}