#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> parent;

int answer = 21e8;

void input() {
	cin >> n >> m;
	
	parent.resize(n);

	for (int i = 0; i < n; ++i) {
		parent[i] = i;
	}

}

int Find(int a) {
	
	if (a == parent[a]) {
		return a;
	}
	
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {

	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB)
		return;

	parent[rootB] = rootA;

	return;
}

void solution() {

	for (int i = 0; i < m; ++i) {
		int u, v;

		cin >> u >> v;

		if (answer != 21e8)
			continue;

		int rootU = Find(u);
		int rootV = Find(v);

		if (rootU == rootV) {
			answer = i + 1;
		}

		Union(rootU, rootV);

	}

	if (answer == 21e8)
		answer = 0;

	cout << answer;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solution();

}