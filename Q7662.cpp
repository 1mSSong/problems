#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int t;

unordered_map<int, int> cnt;
priority_queue<int> MAX_Q;
priority_queue<int, vector<int>, greater<>> MIN_Q;

int answer[2];

void init() {
	cnt.clear();
	
	while (!MAX_Q.empty())
		MAX_Q.pop();

	while (!MIN_Q.empty())
		MIN_Q.pop();

	answer[0] = 21e8;
	answer[1] = 21e8;
}

void insertQ(int num) {
	MAX_Q.push(num);
	MIN_Q.push(num);

	cnt[num]++;
}

void getMax() {

	while (1) {
		if (MAX_Q.empty())
			return;

		int now = MAX_Q.top();

		if (cnt[now] != 0)
			break;

		MAX_Q.pop();
	}
}

void getMin() {

	while (1) {
		if (MIN_Q.empty())
			return;

		int now = MIN_Q.top();

		if (cnt[now] != 0)
			break;

		MIN_Q.pop();
	}
}

void deleteQ(int num) {
	
	if (num == 1) {
		getMax();

		if (!MAX_Q.empty()) {

			if (--cnt[MAX_Q.top()] == 0) {
				MAX_Q.pop();
			}
		}
	}

	else {
		getMin();

		if (!MIN_Q.empty()) {

			if (--cnt[MIN_Q.top()] == 0) {
				MIN_Q.pop();
			}
		}
	}
}

void input() {

	int k;
	cin >> k;

	for (int i = 0; i < k;++i) {
		char order;
		int num;
		
		cin >> order >> num;

		if (order == 'I') {
			insertQ(num);
		}
		else {
			deleteQ(num);
		}
			
	}
}

void solution() {

	getMax();
	getMin();

	if (!MAX_Q.empty()) {
		answer[0] = MAX_Q.top();
	}

	if (!MIN_Q.empty()) {
		answer[1] = MIN_Q.top();
	}

	if (answer[0] == 21e8 || answer[1] == 21e8) {
		cout << "EMPTY\n";
		return;
	}
	
	cout << answer[0] << " " << answer[1] << "\n";
}

int main() {

	cin >> t; 

	for (int i = 0; i < t; ++i) {

		init();

		input();

		solution();
	}
}