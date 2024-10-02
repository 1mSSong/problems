#include <iostream>
#include <vector>
#include <string>
using namespace std; 

int n, k;

vector<int> path;
vector<int> dat;

vector<string> die; // µ¶±Ø¹° Á¶ÇÕ

vector<pair<int, string>> combination;

int ans;
int len;

void input() {
	cin >> n >> k;

	path.resize(n);
	dat.resize(n);
	die.resize(k);

	for (int i = 0; i < k; ++i) {
		cin >> die[i];
	}
}

void dfs(int now) {
	if (now >= n) {
		string tmp = "";

		for (int i = 0; i < n; ++i) {
			if (path[i]) {
				tmp += to_string(i + 1);
			}
		}
		
		if (tmp != "") {
			combination.push_back({ 1, tmp });
		}
		return;
	}

	for (int i = 0; i <= 1; ++i) {
		if (dat[i])
			continue;

		path[now] = i;

		dfs(now + 1);

		path[now] = 0;
	}
}

void solution() {
	dfs(0);

	len = combination.size();

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < k; ++j) {
			if (combination[i].first == 0)
				break;

			int flag = 0;

			for (int a = 0; a < die[j].size(); ++a) {
				if (combination[i].second.find(die[j][a]) == -1) {
					flag = 1;
					break;
				}
			}

			
			if (!flag) {
				combination[i].first = 0;
			}
		}
	}

	
	for (int i = 0; i < len; ++i) {
		if (combination[i].first)
			ans++;
	}
}

int main() {
	input();

	solution();

	cout << ans;

}