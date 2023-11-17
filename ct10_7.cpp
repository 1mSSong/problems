#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> parent;

int findParent(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int chk, a, b;
		cin >> chk >> a >> b;

		if (!chk) {
			unionParent(a, b);
		}
		else {
			if (findParent(a) == findParent(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}