#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> map;
vector<int> cnt;

void input() {
	cin >> n;

	map.resize(n + 1, 0);
	cnt.resize(n + 1, 0);
	
	for (int i = 1; i <= n; ++i) {
		cin >> map[i];
		cnt[map[i]]++;
	}
}

void solution() {
	queue<int> q; // 지울 목록
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = map[q.front()];
		q.pop();

		cnt[now]--;
		if (cnt[now] == 0) {
			q.push(now);
		}
	}
}

void printAnswer() {
	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] != 0) {
			answer++;
		}
	}

	cout << answer << "\n";
	for (int i = 1; i <= n; ++i) {
		if (cnt[i] != 0) {
			cout << i << "\n";
		}
	}
}

int main() {

	input();

	solution();

	printAnswer();
}