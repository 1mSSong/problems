#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string init;
int m;

stack<char> c_left; // 커서 이전
stack<char> c_right; // 커서 이후

void L() {
	if (c_left.empty())
		return;

	c_right.push(c_left.top());
	c_left.pop();
}

void D() {
	if (c_right.empty())
		return;

	c_left.push(c_right.top());
	c_right.pop();
}

void B() {
	if (c_left.empty())
		return;

	c_left.pop();
}

void P(int alpha) {
	c_left.push(alpha);
}

void input() {
	cin >> init;
	cin >> m;

	for (int i = 0; i < init.length(); ++i) {
		c_left.push(init[i]);
	}

	for (int i = 0; i < m; ++i) {
		char c;
		cin >> c;

		if (c == 'L') {
			L();
		}
		else if (c == 'D') {
			D();
		}
		else if (c == 'B') {
			B();
		}
		else if (c == 'P') {
			char alpha;
			cin >> alpha;

			P(alpha);
		}
	}
}

void solution() {

	string answer = "";
	
	while (!c_left.empty()) {
		answer += c_left.top();
		c_left.pop();
	}

	reverse(answer.begin(), answer.end());

	while (!c_right.empty()) {
		answer += c_right.top();
		c_right.pop();
	}

	cout << answer;
}

int main() {

	input();

	solution();
}