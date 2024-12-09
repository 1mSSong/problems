#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int answer = 21e8;

int sum[2];
vector<int> person; // 인구수
vector<vector<int>> graph;
vector<int> group; // 그룹나누기

void input() {
	cin >> n;

	person.resize(n);
	graph.resize(n);
	group.resize(n, -1);

	for (int i = 0; i < n; ++i) {
		cin >> person[i];
	}

	for (int i = 0; i < n; ++i) {
		
		int num;
		cin >> num;
		
		for (int j = 0; j < num; ++j) {
			int from;
			cin >> from;

			graph[i].push_back(from - 1);
		}
	}
}

int bfs(int start) {

	int nowgroup = group[start];

	vector<int> visited(n, -1);

	queue<int> qa;
	qa.push(start);
	visited[start] = 1;

	while (!qa.empty()) {
		int now = qa.front();
		qa.pop();

		visited[now] = 1;

		for (int i = 0; i < graph[now].size(); ++i) {
			int y = graph[now][i];

			if (group[y] != nowgroup)
				continue;

			if (visited[y] == 1)
				continue;

			visited[y] = 1;
			qa.push(y);
		}
	}

	// 연결 확인

	for (int i = 0; i < n; ++i) {
		if (group[i] != nowgroup)
			continue;

		sum[nowgroup] += person[i];

		if (visited[i] == -1) {
			return -1;
		}
	}

	return 1;

}


void solution() {

	int startA = -1, startB = -1;
	sum[0] = 0;
	sum[1] = 0;

	for (int i = 0; i < n; ++i) {
		if (group[i] == 0) {
			startA = i;
			break;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (group[i] == 1) {
			startB = i;
			break;
		}
	}

	// 하나의 그룹
	if (startA == -1 || startB == -1)
		return;


	// 그룹 A 연결 확인
	if (bfs(startA) == -1)
		return;
	
	// 그룹 B 연결 확인
	if (bfs(startB) == -1)
		return;


	answer = min(answer, abs(sum[0] - sum[1]));


}

void dfs(int level) {
	
	if (level == n) {

		solution();

		return;
	}

	for (int i = 0; i < 2; ++i) {
		group[level] = i;

		dfs(level + 1);

		group[level] = -1;
	}
}


int main() {

	input();

	dfs(0);

	(answer == 21e8) ? answer = -1 : 1;
	cout << answer;

}