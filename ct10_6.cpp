#include <iostream>
#include <queue>
using namespace std;

// V : 노드 개수, E :간선 개수
// 노드 개수는 최대 100,000개
int v, e;

// 진입차수 초기화
int indegree[100001];

// 연결된 간선 정보
vector<int> graph[100001];

// 위상 정렬 함수
void topologySort() {
	vector<int> result; // 수행 결과를 담을 리스트
	queue<int> q;

	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		result.push_back(now);

		// 연결된 진입차수 -1
		for (int i = 0; i < graph[now].size(); i++) {
			indegree[graph[now][i]]--;

			// 새롭게 진입차수 0이 되는 노드 큐에 삽입
			if (indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}

int main() {
	cin >> v >> e;

	// 간선 정보 입력받기
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // a -> b;
		indegree[b]++;
	}

	topologySort();
}