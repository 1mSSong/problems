#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> line;
vector<int> isVisited;
int res = 0;

void dfs(int cur) {
	isVisited[cur] = true;

	for (int i = 0; i < line[cur].size(); i++) {
		int next = line[cur][i];
		if (!isVisited[next]) {
			dfs(next);
			res++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, v;
	cin >> n >> v;
	
	line.assign(n + 1, vector<int>(0, 0));
	isVisited.assign(n + 1, false);

	for (int i = 0; i < v; i++) {
		int s, e;
		cin >> s >> e;
		line[s].emplace_back(e);
		line[e].emplace_back(s);
	}
	dfs(1);
	cout << res;
	
}