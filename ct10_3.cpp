#include <iostream>
using namespace std;

// v : 노드 개수, e : 간선 개수 (union 연산 개수)
// 노드의 개수 최대 100,000개
int v, e;
int parent[100001];

// 특정 원소가 속한 집합 찾기
int findParent(int x) {
	// 루트 노드를 찾을 때까지 재귀적으로 호출
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

// union
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	// union 연산 수행
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	cout << "각 원소가 속한 집합 : ";
	for (int i = 1; i <= v; i++) {
		cout << findParent(i) << " ";
	}
	cout << "\n";

	cout << "부모 테이블 : ";
	for (int i = 1; i <= v; i++) {
		cout << parent[i] << " ";
	}
	cout << "\n";
}