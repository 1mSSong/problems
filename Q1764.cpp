#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	map<string, int> input;
	vector<string> res;

	for (int i = 0; i < n + m; i++) {
		string s;
		cin >> s;
		input[s]++;
		if (input[s] > 1) {
			res.push_back(s);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (auto i : res) {
		cout << i << "\n";
	}
}