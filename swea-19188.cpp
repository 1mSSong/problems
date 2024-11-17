#include <iostream>
#include <vector>
using namespace std;

int t;
int n;
vector<int> height;

vector<int> dp;
int answer;

void init() {
	height.clear();
	dp.clear();

	answer = 0;
}

void input() {
	cin >> n;

	height.resize(n);
	dp.resize(n, 1);

	for (int i = 0; i < n; ++i) {
		cin >> height[i];
	}

}

void solution() {

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (height[i] > height[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int index = 0;

	for (int i = 0; i < n; ++i) {
		if (dp[index] < dp[i]) {
			index = i;
		}
	}

	answer = n - dp[index];
}

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		
		init();

		input();

		solution();
		
		cout << "#" << tc << " " << answer << "\n";
	}
}