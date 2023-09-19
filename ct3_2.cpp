#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
vector<int> v;

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	int first = v[n - 1]; // 가장 큰 수
	int second = v[n - 2]; // 두 번째로 큰 수

	// 큰 수가 더해지는 횟수 계산
	int cnt = (m / (k + 1)) * k;
	cnt += m % (k + 1); // 나누어 떨어지지 않을 때를 고려

	int res = 0;
	res += cnt * first;
	res += (m - cnt) * second;

	cout << res << "\n";
}
