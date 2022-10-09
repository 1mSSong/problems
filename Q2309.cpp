#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> height(9);
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}
	sum -= 100;
	int minus[2] = { 0 };
	sort(height.begin(), height.end());
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum == height[i] + height[j]) {
				minus[0] = height[i];
				minus[1] = height[j];
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (height[i] != minus[0] && height[i] != minus[1]) cout << height[i] << endl;
	}
}
