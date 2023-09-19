#include <iostream>
#include <vector>
using namespace std;

int n, m;
int result;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		// 현재 줄에서 '가장 작은 수' 찾기
		int min_value = 10001;

		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			min_value = min(min_value, x);
		}
		// '가장 작은 수' 중 가장 큰 수 찾기
		result = max(result, min_value);

	}

	cout << result << endl;
}