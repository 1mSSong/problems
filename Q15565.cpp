#include <iostream>
using namespace std;

int n, k;
int num[1000010];

int answer = 21e8;

void input() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
}

void solution() {

	// 시작은 무조건 1
	int left = -1, right = -1;

	for (int i = 0; i < n; ++i) {
		if (num[i] == 1) {
			left = i;
			right = i;
			break;
		}
	}

	if (left == -1) {
		answer = -1;
		return;
	}

	// K개의 1
	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		if (num[i] == 1) {
			cnt++;
		}

		if (cnt == k) {
			right = i;
			break;
		}
	}

	if (cnt < k) {
		answer = -1; 
		return;
	}

	answer = min(answer, right - left + 1);

	while (1) {

		// left 다음 1까지 옮기기
		while (1) {

			++left;

			if (left >= n)
				break;

			if (num[left] == 1)
				break;
		}

		// right 옮기기
				// left 다음 1까지 옮기기
		while (1) {

			++right;

			if (right >= n)
				break;

			if (num[right] == 1)
				break;
		}

		if (left >= n || right >= n)
			break;
		
		answer = min(answer, right - left + 1);
	}
}

int main() {

	input();

	solution();

	if (answer == 21e8)
		answer = -1;

	cout << answer;

}