#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n;
int answer;

vector<int> loseHP; // ÀÒ´Â Ã¼·Â
vector<int> getHappy; // ¾ò´Â ±â»Ý
vector<int> path; // ¾Ç¼ö ÇÒ Áö ¾ÈÇÒÁö

void input() {
	cin >> n;

	loseHP.resize(n);
	getHappy.resize(n);
	path.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> loseHP[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> getHappy[i];
	}
}


void calc() {
	int HP = 100;
	int happy = 0;

	for (int i = 0; i < n; ++i) {
		HP -= (loseHP[i] * path[i]);
		happy += (getHappy[i] * path[i]);
	}

	if (HP <= 0)
		return;

	answer = max(answer, happy);
}

void func(int now) {
	if (now == n) {
		calc();
		return;
	}

	for (int i = 0; i < 2; ++i) {

		path[now] = i;

		func(now + 1);

		path[now] = 0;
	}
}

void solution() {

	func(0);

	cout << answer;
}


int main() {

	input();

	solution();
}