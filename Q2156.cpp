#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> grape(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> grape[i];
	}

	vector<int> dp(n + 1);
	dp[1] = grape[1];
	dp[2] =grape[1] + grape[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + grape[i] + grape[i - 1], max(dp[i - 1], dp[i - 2] + grape[i]));
	}
	cout << dp[n];
}