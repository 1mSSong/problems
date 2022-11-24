#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector<long> dp(n + 1);
	dp[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		long num;
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << "\n";
	}
}