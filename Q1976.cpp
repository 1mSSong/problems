#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> parent;
vector<int> path;


int Find(int a) {

	if (parent[a] == a)
		return a;

	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {

	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB)
		return;

	parent[rootB] = rootA;
}

void input() {
	cin >> n >> m;

	graph.resize(n + 1);
	path.resize(m);
	parent.resize(n + 1);
	
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1;j <= n; ++j) {
			
			int num;
			cin >> num;

			if (num) {
				Union(i, j);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		cin >> path[i];
	}
}

void solution() {

	int chk = parent[path[0]];

	for (int i = 1; i < m; ++i) {
		int rootA = Find(parent[path[i]]);
		if (rootA != chk) {
			cout << "NO";
			return;
		}
	}

	cout << "YES";
}


int main() {
	
	input();

	solution();

}