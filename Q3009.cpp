#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<pair<int, int>> dot(4);

	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		dot[i] = make_pair(a, b);
	}
	if (dot[0].first == dot[1].first) {
		dot[3].first = dot[2].first;
	}
	else if (dot[0].first == dot[2].first) {
		dot[3].first = dot[1].first;
	}
	else {
		dot[3].first = dot[0].first;
	}

	if (dot[0].second == dot[1].second) {
		dot[3].second = dot[2].second;
	}
	else if (dot[0].second == dot[2].second) {
		dot[3].second = dot[1].second;
	}
	else {
		dot[3].second = dot[0].second;
	}
	cout << dot[3].first << " " << dot[3].second;
}