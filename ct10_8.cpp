#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[100001];
vector<pair<int, pair<int, int>>> edges;
int res = 0;


int findParent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}


	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edges.push_back({cost, { a, b }});
	}

	sort(edges.begin(), edges.end());
	int last = 0; // 최소 신장 트리에 포함되는 간선 중에 가장 비용이 큰 간선

	for (int i = 0; i < m; i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		if (findParent(a) != findParent(b)) {
			res += cost;
			unionParent(a, b);
			last = cost;
		}
	}
	cout << res - last << "\n";
}