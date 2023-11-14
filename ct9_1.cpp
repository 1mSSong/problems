#include <iostream>
#include <vector>
#define INF 1e9 // 무한을 의미하는 값
using namespace std;

// n : 노드의 개수, m : 간선의 개수, start : 노드 시작 번호
// 노드 최대 100,000개라고 가정
int n, m, start; 
vector<pair<int, int>> graph[100001];

// 방문한 적이 있는지 체크하는 배열
bool visited[100001];

// 최단 거리 테이블 만들기
int d[100001];

// 방문하지 않은 노드 주에서 가장 최단 거리가 짧은 노드 번호 반환
int getSmallestNode() {
	int min_value = INF;
	int index = 0;

	for (int i = 1; i <= n; i++) {
		if (d[i] < min_value && !visited[i]) {
			min_value = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	// 시작 노드 초기화
	d[start] = 0;
	visited[start] = true;

	for (int j = 0; j < graph[start].size(); j++) {
		d[graph[start][j].first] = graph[start][j].second;
	}

	// 시작 노드를 제외한 전체 n - 1개의 노드에 대해서 반복
	for (int i = 0; i < n - 1; i++) {
		// 현재 최단 거리가 가장 짧은 노드를 꺼내 방문
		int now = getSmallestNode();
		visited[now] = true;

		// 현재 노드와 연결된 노드 확인
		for (int j = 0; j < graph[now].size(); j++) {
			int cost = d[now] + graph[now][j].second;

			// 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우 갱신
			if (cost < d[graph[now][j].first]) {
				d[graph[now][j].first] = cost;
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// a번 노드에서 b번 노드로 가는 비용이 c
		graph[a].push_back({ b, c });
	}

	// 최단 거리 테이블 초기화
	fill_n(d, 100001, INF);

	// 다익스트라 알고리즘 수행
	dijkstra(start);

	// 모든 노드로 가기 위한 최단 거리 출력
	for (int i = 1; i <= n; i++) {
		if (d[i] == INF) {
			cout << "INFINITY\n";
		}
		else {
			cout << d[i] << "\n";
		}
	}
}
