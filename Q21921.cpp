#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, x;
int num[250001];

map<int, int, greater<int>> cnt;

void input() {
	cin >> n >> x;

	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
}

void solution() {

	queue<int> now;

	int index = x;
	int sum = 0;

	for (int i = 0; i < x; ++i) {
		now.push(num[i]);
		sum += num[i];
	}
	cnt[sum]++;

	
	for (int i = index; i < n; ++i) {
		sum -= now.front();
		now.pop();

		sum += num[i];
		now.push(num[i]);

		cnt[sum]++;
	}

	auto answer = *cnt.begin();

	if (answer.first == 0) {
		cout << "SAD\n";
		return;
	}

	cout << answer.first << "\n" << answer.second;
}

int main() {

	input();

	solution();
}