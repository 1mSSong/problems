#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> card;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		card.push(a);
	}
	
	int res = 0;
	while (card.size() > 1) {
		int tmp = 0;
		tmp += card.top();
		card.pop();
		tmp += card.top();
		card.pop(); 
		res += tmp;
		card.push(tmp);
	}
	cout << res;

}