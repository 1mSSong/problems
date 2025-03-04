#include <iostream>
#include <vector>
using namespace std;

int n;

vector<int> answer;
vector<int> order;

void input() {
	
	cin >> n;

	answer.resize(n, 0);
	order.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> order[i];
	}
}

void solution() {

	for (int i = 0; i < n; ++i) {
		
		int cnt = 0;

		for (int j = 0; j < n; ++j) {

			if (answer[j] != 0) {
				continue;
			}

			if (cnt == order[i]) {
				answer[j] = i + 1;
				break;
			}

			cnt++;
		}
	}
}

void printAnswer() {
	
	for (int i = 0; i < n; ++i) {
		cout << answer[i] << " ";
	}
}

int main() {

	input();

	solution();

	printAnswer();
}