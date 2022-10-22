#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, string>> P(N);

	for (int i = 0; i < N; i++) {
		cin >> P[i].first>>P[i].second;
	}
	
	stable_sort(P.begin(), P.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << P[i].first << " " << P[i].second << "\n";
	}

}