#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unsigned int k, n, ans = 0;
	cin >> k >> n;
	vector<unsigned int> list(k);

	unsigned int maxi = 0;
	for (int i = 0; i < k; i++) {
		cin >> list[i];
		maxi = max(maxi, list[i]);
	}

	unsigned int left = 1, right = maxi, mid;
	
	while (left <= right) {
		mid = (left + right) / 2;
		unsigned int cnt = 0;

		for (int i = 0; i < k; i++) {
			cnt += (list[i] / mid);
		}

		if (cnt >= n) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << "\n";

}