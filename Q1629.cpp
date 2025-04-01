#include <iostream>
#include <vector>
using namespace std;

int a, b, c;
long long answer = 1;

void input() {
	cin >> a >> b >> c;
}

void solution() {
	
	long long now = a % c;

	while (b) {
		if (b & 1) {
			answer = (answer * now) % c;
		}

		b >>=  1;
		
		now = (now * now) % c;
	}

	cout << answer;
}

int main() {

	input();

	solution();
}