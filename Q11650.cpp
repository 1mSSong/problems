#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pair<int, int>> dot(N);
	
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		dot[i] = make_pair(x, y);
	}
	sort(dot.begin(), dot.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << dot[i].first << " " << dot[i].second << "\n";
	}
}