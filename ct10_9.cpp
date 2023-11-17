#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int indegree[501];
vector<int> graph[501];
int times[501];

void topologySort() {
	vector<int> result(501);
	for (int i = 1; i <= n; i++) {
		result[i] = times[i];
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
			indegree[graph[now][i]]--;

			if (indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);
		}
	 }

	for (int i = 1; i <= n; i++) {
		cout << result[i] << "\n";
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		times[i] = x;

		while (true) {
			cin >> x;
			if (x == -1) break;

			indegree[i]++;
			graph[x].push_back(i);
		}
	}

	topologySort();
}
