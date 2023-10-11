#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	// DP 테이블 초기화
	vector<int> d(m + 1, 100001);

	d[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= m; j++) {
			d[j] = min(d[j], d[j - arr[i]] + 1);
		}
	}

	if (d[m] == 10001)
		cout << -1;
	else
		cout << d[m];
}
