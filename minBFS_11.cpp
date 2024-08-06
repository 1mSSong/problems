#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100001;
int coco, school;
int visited[MAX];

int bfs(int start) {
	// À§Ä¡, time
	queue<pair<int, int>> q;

	q.push({ start, 0 });
	visited[start] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second;

		q.pop();

		if (x == school)
			return t;

		if (x + 1 < MAX && !visited[x + 1]) {
			visited[x + 1] = 1;
			q.push({ x + 1, t + 1 });
		}

		if (x - 1 >= 0 && !visited[x - 1]) {
			visited[x - 1] = 1;
			q.push({ x - 1, t + 1 });
		}

		if (2 * x < MAX && !visited[2 * x]) {
			visited[2 * x] = 1;
			q.push({ 2 * x, t + 1 });
		}
	}

}

int main() {
	cin >> coco >> school;
	
	cout << bfs(coco);
}