#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;


struct Coord {
	int y, x;
};

Coord coords[21];

int t;

int n;
int visited[21];

ll ans;

int Plus; // 움직이지 않는 지렁이
int Minus; // 움직이는 지렁이

void init() {
	memset(visited, 0, sizeof(visited));
	Plus = 1;
	Minus = 0;
	ans = 999999999999;
}

void input() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> coords[i].x >> coords[i].y;
	}
}

void dfs(int now, ll sumX, ll sumY) {
	if (Plus == n / 2 && Minus == n / 2) {
		ll ret = sumX * sumX + sumY * sumY;

		ans = min(ans, ret);
	}

	// 움직이지 않는 지렁이의 벡터합
	if (n / 2 > Plus) {
		Plus++;
		
		dfs(now + 1, sumX + coords[now + 1].x, sumY + coords[now + 1].y);
		
		Plus--;
	}

	// 움직이는 지렁이들의 벡터합
	if (n / 2 > Minus) {
		Minus++;

		dfs(now + 1, sumX - coords[now + 1].x, sumY - coords[now + 1].y);

		Minus--;
	}

	return;
}

void solution() {
	dfs(0, coords[0].x, coords[0].y);
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		solution();

		cout << "#" << tc << " " << ans << "\n";
	}
}