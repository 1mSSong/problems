#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int res = 1;
		vector< pair<int, int>> rank(n);

		for (int j = 0; j < n; j++) {
			cin >> rank[j].first >> rank[j].second;
		}
		sort(rank.begin(), rank.end());
		int tmp = rank[0].second;

		for (int j = 1; j < n; j++) {
			if (rank[j].second < tmp) {
				res++;
				tmp = rank[j].second;
			}
		}
		cout << res << "\n";
	}
}