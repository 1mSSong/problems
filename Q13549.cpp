#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
vector<int> visited;

void input() {
	cin >> n >> k;


	visited.resize(2 * max(n, k) + 10, 21e8);
}

void bfs() {
	
	queue<int> q;

	visited[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int all_next[3] = { now - 1, now + 1, now * 2 };
		
		for (int i = 0; i < 3; ++i) {
			int next = all_next[i];

			if (next < 0 || next >= 2 * max(n, k) + 10)
				continue;


			// +- 1Ä­
			if (i != 2) {
			
				if (visited[next] > visited[now] + 1) {
					visited[next] = visited[now] + 1;
					q.push(next);
				}
			}

			// 2¹è
			else if (i == 2) {
				if (visited[next] > visited[now]) {
					visited[next] = visited[now];
					q.push(next);
				}
			}

		}
	}
}

void solution() {

	bfs();

	cout << visited[k];
}

int main() {
	
	input();

	solution();
}