#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> cnt(n + 4);
	
	cnt[0] = 0;
	cnt[1] = 0;

	for (int i = 2; i <= n; i++) {
		cnt[i] = cnt[i - 1] + 1;
		if (i % 3 == 0) {
			cnt[i] = min(cnt[i], 1 + cnt[i / 3]);
		}
		if (i % 2 == 0) {
			cnt[i] = min(cnt[i], 1 + cnt[i / 2]);
		}
	}
	cout << cnt[n];
}