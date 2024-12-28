#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, m;
int k;

unordered_map<int, int> tmp; // input
vector<pair<int, int>> dat;

vector<int> path;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		
		int num;
		cin >> num;

		tmp[num]++;
	}

	for (auto item : tmp) {
		dat.push_back(item);
	}
	
	k = dat.size();
}

void dfs(int level, int idx) {

	if (level == m) {
		
		for (int i = 0; i < m; ++i) {
			cout << path[i] << " ";
		}
		cout << '\n';

		return;
	}

	for (int i = idx; i < k; ++i) {
		
		if (dat[i].second == 0)
			continue;

		path.push_back(dat[i].first);

		dat[i].second--;

		dfs(level + 1, idx);

		path.pop_back();

		dat[i].second++;

	}
}

void solution() {

	sort(dat.begin(), dat.end());

	dfs(0, 0);

}

int main() {

	input();

	solution();
}