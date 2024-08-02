#include <iostream>
#include <vector>
using namespace std;

int n;
int sum = 0;
int maxsum = 0;
int index = 0;

// node, cost
vector<vector<pair<int, int>>> graph;
vector<int> visited;

void init() {
	visited.clear();
	visited.resize(n + 1);
	
	sum = 0;
	maxsum = 0;

}

void input() {

	cin >> n;

	graph.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
}

void dfs(int x) {
	visited[x] = 1;


	for (int i = 0; i < graph[x].size(); ++i) {
		int y = graph[x][i].first;

		if (visited[y] == 1) {
			continue;
		}

		visited[y] = 1;
		sum += graph[x][i].second;

		dfs(y);

		visited[y] = 0;
		sum -= graph[x][i].second;
	}

	if (sum > maxsum) {
		maxsum = sum;
		index = x;
		return;
	}
	
}

void solution() {

}



int main() {
	
	input();

	dfs(1);

	init();

	dfs(index);

	cout << maxsum;
}