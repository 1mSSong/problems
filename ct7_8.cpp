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

	int start = 0;
	// 최대 길이의 떡을 최댓값으로 하려면 또 찾아야 함 -> 시간 소요
	int end = 1e9;

	int res = 0;
	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;

		// 잘랐을 때의 떡 양 계산
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid) total += arr[i] - mid;
		}

		// 떡의 양이 부족한 경우
		if (total < m)
			end = mid - 1;
		// 떡의 양이 충분한 경우
		else {
			// 최대한 덜 잘랐을 때가 정답
			res = mid;
			start = mid + 1;
		}
	}

	cout << res;
}