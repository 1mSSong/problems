#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;

vector<int> path;

int index;
int now; // 현재까지의 합

string  answer;
int flag = 0;

void chk(int level) {

	if (level == index) {

		now++;

		if (n == now) {
			flag = 1;
			
			for (int i = 0; i < path.size(); ++i) {
				answer += to_string(path[i]);
			}
		}
		return;
	}

	for (int i = 0; i <= 9; ++i) {
		if (level == 0 && i == 0)
			continue;

		if (level > 0 && path[level - 1] <= i)
			continue;

		path[level] = i;

		chk(level + 1);

		if (flag)
			break;

		path[level] = 0;
	}

	if (flag)
		return;
}

void solution() {

	for (int i = 1; i <= 10; ++i) {

		path.clear();
		path.resize(i);

		index = i;

		chk(0);
	
	}

}

int main() {
	
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	solution();

	if (n > now)
		cout << -1;
	else {
		cout << answer;
	}

}