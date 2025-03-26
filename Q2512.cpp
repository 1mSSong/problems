#include <iostream>
using namespace std;

int n, m;
int offer[100001];

int sum;
int answer;

void input() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> offer[i];

		sum += offer[i];
		answer = max(answer, offer[i]);
	}

	cin >> m;
}


void solution() {

	int left = 0, right = answer;

	// ��� ��û ���� ����
	if (sum <= m)
		return;

	// �Ұ��� -> �̺�Ž������ ã��
	
	answer = 0;

	while (1) {

		if (left > right) {
			answer = right;
			break;
		}
		int mid = (left + right) / 2;
		sum = 0;

		for (int i = 0; i < n; ++i) {
			sum += min(offer[i], mid);
		}

		if (sum > m)
			right = mid - 1;

		else
			left = mid + 1;
	}
}

int main() {
	
	input();

	solution();

	cout << answer;

	return 0;
}