#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

struct Info {
	int left;
	int right;
	int period;

	bool operator < (Info& right) const {
		return period > right.period;
	}
};

bool cmp(pii a, pii b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int n;
int answer;
int now_max;

vector<int> order;

void input() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		order.push_back(num);
	}
}

void solution() {

	sort(order.begin(), order.end(), greater<>());
	
	vector<pii> line;

	for (int i = 0; i < n; ++i) {
		
		// ½ÃÀÛ: 0, ³¡: 1
		line.push_back({ i + 1, 0 });
		line.push_back({ i + 1 + order[i], 1 });
	}
	
	sort(line.begin(), line.end(), cmp);
	

	for (int i = 0; i < 2 * n; ++i) {
		if (line[i].second == 0) {
			now_max++;
		}
		else {
			now_max--;
		}

		answer = max(answer, now_max);
	}
	cout << answer;
}

int main() {
	input();

	solution();
}