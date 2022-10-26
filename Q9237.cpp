#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int i, int j) {
	return i > j;
}

int main() {
	int n;
	cin >> n;
	vector<int> t(n);
	
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	sort(t.begin(), t.end(), compare);
	
	int max = 0;
	max = 1 + t[0];
	for (int i = 1; i < n; i++) {
		if (i + 1 + t[i] > max) max = i + 1 + t[i];
	}
	cout << max + 1;
}