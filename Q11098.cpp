#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<pair<int, string>> player;
		int p;
		cin >> p;
		for (int j = 0; j < p; j++) {
			int a;
			string name;
			cin >> a >> name;
			player.push_back(make_pair(a, name));
		}

		sort(player.begin(), player.end());
		cout << player[player.size() - 1].second << "\n";
	}
}