#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int flag; // 답 여부
vector<int> num; // 집합 X
vector<vector<int>> order; // 특정 순서 위치
int DAT[17]; // 숫자 사용 횟수
vector<int> path;

void input() {
	cin >> n;

	num.resize(n);
	path.resize(2 * n);
	order.resize(17);

	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());
}

void chkAnswer() {

	for (int i = 0; i < 2 * n; ++i) {

		int now = path[i];
		if ((order[now][1] - order[now][0] - 1) != now) {
			return;
		}
	}

	flag = 1;
	return;
}

void dfs(int level) {

	if (level == 2 * n) {
		chkAnswer();
		return;
	}
	
	for (int i = 0; i < n; ++i) {
		if (DAT[num[i]] >= 2)
			continue;

		path[level] = num[i];
		DAT[num[i]]++;
		order[num[i]].push_back(level);

		if (order[num[i]].size() == 2) {
			if ((order[num[i]][1] - order[num[i]][0] - 1) != num[i]) {
				path[level] = 0;
				DAT[num[i]]--;
				order[num[i]].pop_back();
				continue;
			}
		}

		dfs(level + 1);

		if (flag)
			break;

		path[level] = 0;
		DAT[num[i]]--;
		order[num[i]].pop_back();
	}
}

void solution() {

	dfs(0);

	if (!flag) {
		cout << -1;
		return;
	}

	for (int i = 0; i < 2 * n; ++i) {
		cout << path[i] << " ";
	}
}

int main() {
	
	input();

	solution();
}