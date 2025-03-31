#include <iostream>
#include <queue>
using namespace std;

vector<int> dist;
int f, s, g, u, d;

int moves[2]; // ÀÌµ¿

void input() {
	cin >> f >> s >> g >> u >> d;

	moves[0] = u;
	moves[1] = -d;

	dist.resize(f + 1, 21e8);
}

void solution() {

	queue<int> q;

	dist[s] = 0;
	q.push(s);


	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == g)
			return;

		for (int i = 0; i < 2; ++i) {
			int next = now + moves[i];

			if (next > f || next <= 0)
				continue;

			if (dist[next] <= dist[now] + 1)
				continue;

			dist[next] = dist[now] + 1;
			q.push(next);
		}
	}
}

int main() {
	input();

	solution();

	if (dist[g] == 21e8) {
		cout << "use the stairs\n";
	}
	else {
		cout << dist[g];
	}
	
}