#include <iostream>
using namespace std;

int chk[9];

void reset() {
	for (int i = 0; i < 10; i++) {
		chk[i] = 0;
	}
}

void solution() {
	string s;
	cin >> s;

	reset();

	for (int i = 0; i < s.size(); i++) {
		chk[s[i] - '0']++;
	}

	int res = 0;
	
	for (int i = 0; i < 10; i++) {
		if (chk[i] > 0)
			res++;
	}

	cout << res << "\n";
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solution();
	}
}