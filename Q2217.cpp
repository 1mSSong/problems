#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	int n;
	cin >> n;
	vector<int> rope(n);

	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope.begin(), rope.end(), compare);
	int max = rope[0];
	for (int i = 1; i < n; i++) {
		if (max < rope[i] * (i + 1)) {
			max = rope[i] * (i + 1);
		}

	}
	cout << max;
}