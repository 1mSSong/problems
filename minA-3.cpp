#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;
int n;

int sum[2]; // 0 : A 지역구, 1 : B 지역구

int res; // 최솟값 (결과)

vector<vector<int>> graph; // 연결 그래프
vector<int> arr; // 유권자 수

vector<int> group; // 지역구 나누기 1 : 지역구 A, 2 : 지역구 B
vector<int> visited; // 연결되어 있는지 확인

void init() {
	graph.clear();
	arr.clear();
	group.clear();
	visited.clear();

	sum[0] = 0;
	sum[1] = 0;
	res = 2e9;

}

void input() {
	cin >> n;

	group.resize(n);
	graph.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int tmp;
			cin >> tmp;

			if (tmp) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	arr.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}


// 연결 되어 있으면 true
// 그렇지 않으면 false 
bool bfs(int start, int nowGroup) {
	visited.clear();
	visited.resize(n);

	queue<int> q;

	visited[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); ++i) {
			int y = graph[x][i];

			// 이미 방문
			if (visited[y])
				continue;
			
			if (group[y] != nowGroup)
				continue;
			
			visited[y] = 1;
			q.push(y);
		}
	}

	// 연결되어 있는지 확인
	for (int i = 0; i < n; ++i) {
		// group 에 속할 때만 확인
		if (group[i] != nowGroup)
			continue;

		if (visited[i] == 0) {
			sum[nowGroup - 1] = 0;
			return false;
		}
			
		sum[nowGroup - 1] += arr[i];
	}

	return true;

}

void solution() {

	sum[0] = 0;
	sum[1] = 0;

	int a = -1; // 처음 지역구 A가 나오는 마을
	int b = -1; // 처음 지역구 B가 나오는 마을

	for (int i = 0; i < n; ++i) {
		if (group[i] == 1) {
			a = i;
			break;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (group[i] == 2) {
			b = i;
			break;
		}
	}

	// 모든 마을이 하나의 지역구
	if (a == -1 || b == -1) {
		return;
	}


	// 유효하지 않은 지역구
	if (!bfs(a, 1)) return;


	if (!bfs(b, 2)) return;

	if (abs(sum[0] - sum[1]) < res) {
		res = abs(sum[0] - sum[1]);
	}
	return;
}

void dfs(int now) {
	if (now >= n) {
		// 지역구 유권자 수 비교
		solution();
		return;
	}

	for (int i = 1; i <= 2; ++i) {
		// 실행
		group[now] = i;

		// 다음 단계
		dfs(now + 1);

		// 복구
		group[now] = 0;

	}
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		dfs(0);

		cout << "#" << tc << " " << res << endl;
	}
}