#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	queue<int> num;
	for (int i = 1; i <= N; i++) {
		num.push(i);
	}
	while (num.size() != 1) {
		num.pop();
		num.push(num.front());
		num.pop();
	}
	cout << num.front();
}