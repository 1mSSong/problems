#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

vector<vector<int>> graph;
vector<int> inDegree;

queue<int> q;

void input() {

	cin >> n >> m;

	graph.resize(n + 1);
	inDegree.resize(n + 1);

	for (int i = 0; i < m; ++i) {
		
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		inDegree[b]++;
	}
}

void solution() {

	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while(!q.empty()) {

		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int j = 0; j < graph[now].size(); ++j) {
			
			inDegree[graph[now][j]]--;
		
			if (inDegree[graph[now][j]] == 0) {
				q.push(graph[now][j]);
			}
		}

	}

}

int main() {
	
	input();

	solution();

}