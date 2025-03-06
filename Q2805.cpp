#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> tree;

int answer;
int min_h = 0, max_h = 21e8;

void input() {
	
	cin >> n >> m;
	tree.resize(n, 0);

	for (int i = 0; i < n;++i) {
		cin >> tree[i];
	}
}

long long getSum(int mid) {
	long long sum = 0;

	for (int i = 0; i < n; ++i) {
		sum += max(0, tree[i] - mid);
	}

	return sum;
}

void binarySearch() {
	
	long long mid_h = 0;
	
	while (1) {
		
		if ((max_h - min_h) <= 2)
			break;
		
		mid_h = (max_h + min_h) / 2;
		long long sum = getSum(mid_h);

		if (sum >= m)
			min_h = mid_h;
		else
			max_h = mid_h;
	}
}

void solution() {

	binarySearch();

	int answer = -1;

	for (int i = max_h; i >= min_h; --i) {
		long long sum = getSum(i);

		if (sum == m) {
			answer = i;
			break;
		}
	}

	// 나무를 정확히 자를 수 없음
	if (answer == -1) {

		int min_diff = 21e8;
		answer = min_h;

		for (int i = min_h; i <= max_h; ++i) {
			long long sum = getSum(i);

			if (sum < m)
				continue;

			if ((sum - m) < min_diff) {
				min_diff = (sum - m);
				answer = i;
			}
		}
	}

	cout << answer;
}

int main() {

	input();

	solution();
}