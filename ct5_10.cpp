#include <iostream>
using namespace std;


int n, m;
int graph[1001][1001];

// DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
bool dfs(int x, int y) {
	// 주어진 범위를 벗어나면 즉시 종료
	if (x <= -1 || x >= n || y <= -1 || y >= m)
		return false;

	// 현재 노드를 방문하지 않았다면
	if (graph[x][y] == 0) {
		// 해당 노드 방문처리
		graph[x][y] = 1;

		//상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true;
	}
	return false;
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 공백 없이 주어지기 때문에 scanf를 이용하여 graph에 값 넣어주기
			scanf("%1d", &graph[i][j]);
		}
	}

	// 모든 노드에 대하여 음료수 채우기
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 현재 위치에서 DFS 수행
			if (dfs(i, j))
				ans++;
		}
	}
	cout << ans;
}