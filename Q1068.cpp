#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;

int n;
int del;
int res = 0;
int snode = 0;

void init() {
	cin >> n;

	graph.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;

		if (tmp == -1) {
			snode = i;
			continue;
		}
		
		graph[tmp].push_back(i);
	}

	cin >> del;

}


void dfs(int x) {
	visited[x] = 1;
	
	if (x == del) {
		return;
	}

	/*
	if (graph[x].size() == 0) {
		res++;
	}
	else if (graph[x].size() == 1) {
		if (graph[x][0] == del) {
			res++;
		}
	}*/
	int cnt = 0;

	for (int i = 0; i < graph[x].size(); ++i) {
		int y = graph[x][i];

		if (visited[y]) {
			continue;
		}

		if (y == del) {
			continue;
		}

		cnt++;

		dfs(y);
	}

	if (!cnt) {
		res++;
	}
	
}

void solution() {
	dfs(snode);
}

int main() {
	init();

	solution();

	cout << res;
}