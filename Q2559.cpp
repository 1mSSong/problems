#include <iostream>
#include <vector>
using namespace std;

int n, k;
int answer = -21e8;

vector<int> temp;

void input() {
	cin >> n >> k;

	temp.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> temp[i];
	}
}

void solution() {
	int left = 0, right = k - 1;
	int sum = 0;

	for (int i = 0; i < k; ++i) {
		sum += temp[i];
	}

	answer = max(answer, sum);

	while (1) {

		sum -= temp[left];

		left++;
		right++;


		if (right >= n) {
			break;
		}

		sum += temp[right];

		answer = max(answer, sum);
	}

	cout << answer;
}


int main() {

	input();

	solution();
}