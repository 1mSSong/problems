#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t;
int n, m;
int answer;

int cmp; // 1이 n개
int lastN; // 2진수의 마지막 n자리

string res[2] = { "OFF", "ON" };

void init() {
	
	answer = 0;

	lastN = 0;
	cmp = 0;
}

void input() {
	
	cin >> n >> m;

	cmp = (1 << n) - 1;
}

void binary() {

	for (int i = n - 1; i >= 0; --i) {

		// lastN을 0 / 1로 바꾸기
		lastN |= ((m % 2) << i);

		m /= 2;
	}

}

int main() {
	
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {

		init();

		input();

		binary();

		if (cmp == lastN) {
			answer = 1;
		}

		cout << "#" << tc << " " << res[answer] << "\n";

	}
}