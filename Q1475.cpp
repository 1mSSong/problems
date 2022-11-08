#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}
int main() {
	string n;
	cin >> n;
	
	vector<pair<int, int>> num(10);

	for (int i = 0; i < 10; i++) {
		num[i].first = i;
		num[i].second = 0;
	}

	for (int i = 0; i < n.length(); i++) {
		num[n[i] - '0'].second++;
	}
	int max = num[0].second;
	for (int i = 1; i < 10; i++) {
		if (max < num[i].second) max = num[i].second;
	}

	if (num[6].second == max || num[9].second) {
		int tmp = (int)(((num[6].second + num[9].second) / 2.0) + 0.5);
		num[6].second = tmp;
		num[9].second = tmp;
	}
	max = num[0].second;
	for (int i = 1; i < 10; i++) {
		if (max < num[i].second) max = num[i].second;
	}
	cout << max;
}