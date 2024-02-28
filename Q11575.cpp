#include <iostream>
#include <string>
using namespace std;

void solution() {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;

	for (char c : s) {
		cout << char((a * (c - 'A') + b) % 26 + 'A');
	}
	cout << "\n";
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solution();
	}
}