#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

// n : ��� ����, m : ���� ����, start : ���� ��� ��ȣ
// ��� ���� �ִ� 100,000�� ����
int n, m, start;

// �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭
vector<pair<int, int>> graph[100001];

// �ִ� �Ÿ� ���̺�
int d[100001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;

	// ���� ���� ���� ���� �ִ� ��δ� 0���� �����Ͽ� ť�� ����
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		// ���� �ִ� �Ÿ��� ª�� ��忡 ���� ���� ������
		int dist = -pq.top().first; // ���� �������� ���
		int now = pq.top().second; // ���� ���
		pq.pop();

		// ���� ��尡 �̹� ó���� ���� �ִ� ����� ����
		if (d[now] < dist)
			continue;

		// ���� ���� ����� �ٸ� ������ ��� Ȯ��
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;

			// ���� ��带 ���ļ� �̵��ϴ� �Ÿ��� �� ª�� ���
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				// C++ �켱���� ť�� �ִ��� -> �ּ������� �����ϱ� ����
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// a�� ��忡�� b�� ���� ���� ����� c��� �ǹ�
		graph[a].push_back({ b, c });
	}

	// �ִ� �Ÿ� ���̺� �ʱ�ȭ
	fill_n(d, 100001, INF);

	// ���ͽ�Ʈ�� �˰����� ����
	dijkstra(start);

	// �ִ� �Ÿ� ���
	for (int i = 1; i <= n; i++) {
		if (d[i] == INF)
			cout << "INFINITY\n";
		else
			cout << d[i] << "\n";
	}
}