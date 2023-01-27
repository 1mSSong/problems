#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<string, string>> per(n);
	for (int i = 0; i < n; i++) {
		cin >> per[i].first >> per[i].second;
	}
	sort(per.begin(), per.end());

	vector<pair<string, int>> in;
	in.push_back(make_pair(per[0].first, 1));
	
	for (int i = 1; i < n; i++) {
		if (per[i].first == per[i - 1].first) {
			in[in.size() - 1].second++;
		}
		else {
			in.push_back(make_pair(per[i].first, 1));
		}
	}

	for (int i = in.size() - 1; i >= 0; i--) {
		if (in[i].second % 2 != 0) {
			cout << in[i].first << "\n";
		}
	}
}