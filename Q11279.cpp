#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>> q;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a != 0) {
			q.push(a);
		}
		else {
			if (q.empty()) {
				cout << "0\n";
			}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}
}