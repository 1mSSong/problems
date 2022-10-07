#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);
int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> time;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		time.push_back(make_pair(a, b));
	}

	sort(time.begin(), time.end(), compare);

	int Stime = 0;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		if (Stime <= time[i].first) {
			cnt++;
			Stime = time[i].second;
		}
	}
	cout << cnt;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}