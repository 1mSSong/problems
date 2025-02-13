#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, int> ladder_snake;

int visited[101]; // 방문여부
int map[101]; // 최소 카운트

void input() {
	cin >> n >> m;


	for (int i = 0; i < n + m; ++i) {
		int x, y;
		cin >> x >> y;

		ladder_snake[x] = y;
	}
	
	for (int i = 0; i <= 100; ++i) {
		map[1] = 21e8;
	}
}

void solution() {
	
	queue<int> q;

	visited[1] = 1;
	map[1] = 0;

	q.push(1);

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; ++i) {
			int next = i + now;

			if (next == 100) {
				map[100] = map[now] + 1;
				return;
			}
			
			if (next > 100)
				continue;

			if (ladder_snake[next] != 0) {
				
				next = ladder_snake[next];
				//map[ladder_snake[next]] = map[now] + 1;
			}

			if (visited[next])
				continue;
			else {
				map[next] = map[now] + 1;
				visited[next] = 1;
				q.push(next);
			}
				
		}
	}

}

int main() {
	input();

	solution();

	cout << map[100];
}