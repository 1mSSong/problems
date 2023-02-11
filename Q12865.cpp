#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// n: 물품의 수, k : 버틸 수 있는 무게
	int n, k;
	cin >> n >> k;

	// w: 물건의 무게, v: 물건의 가치
	vector<int> w(n + 1);
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (w[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[n][k];
}