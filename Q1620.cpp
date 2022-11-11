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
	map<string, int> poketmon;
	vector<string> poketmon_name;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		poketmon[s] = i + 1;
		poketmon_name.push_back(s);
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (poketmon.find(s) != poketmon.end()) {
			cout << poketmon[s] << "\n";
		}
		else {
			int a = stoi(s);
			cout << poketmon_name[a - 1] << "\n";
		}
	}
}