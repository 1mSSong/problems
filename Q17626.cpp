#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[1] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[1] + dp[i - 1];
		for (int j = 2; j <= sqrt(i); j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n];
}