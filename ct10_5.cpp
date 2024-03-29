#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// V : 노드 개수, E : 간선 개수 (union 연산 횟수)
// 노드 개수 최대 100,000개라고 가정
int v, e;

// 부모 테이블 초기화
int parent[100001];

// 모든 간선을 담을 리스트
vector < pair<int, pair<int, int>>> edges;
int result = 0;

// 특정 원소가 속한 집합 찾기
int findParent(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = findParent(parent[x]);
}

// union
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	// 간선 정보 입력 받기
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		// 비용순으로 정렬하기 위해 첫 번째 원소를 비용으로 설정
		edges.push_back({ cost, {a, b} });
	}

	sort(edges.begin(), edges.end());

	// 간선 하나씩 확인
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		// 사이클이 발생하지 않는 경우에만 집합에 포함
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += cost;
		}
	}

	cout << result << endl;
}