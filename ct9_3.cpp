#include <iostream>
#define INF 1e9
using namespace std;

// n : 노드 개수, m : 간선 개수
// 노드 개수 최대 500개
int n, m;

// 2차원 배열
int graph[501][501];

int main() {
	cin >> n >> m;

	// 최단 거리 테이블 무한으로 초기화
	for (int i = 0; i < 501; i++) {
		fill(graph[i], graph[i] + 501, INF);
	}

	// 자신에서 자신으로 가는 건 0으로 초기화
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b)
				graph[a][b] = 0;
		}
	}

	// 각 간선에 대한 정보를 입력 받아 그 값으로 초기화
	for (int i = 0; i < m; i++) {
		// a에서 b로 가는 비용 c
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	// 점화식에 따라 플로이드 워셜 알고리즘 수행
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}
	
	// 결과 출력
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (graph[a][b] == INF)
				cout << "INFINITY ";
			else
				cout << graph[a][b] << " ";
		}
		cout << "\n";
	}
}