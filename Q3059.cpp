#include <iostream>
using namespace std;

int check[26];

void reset() {
	for (int i = 0; i < 26; i++) {
		check[i] = i + 65;
	}
}

void solution() {
	string s;
	cin >> s;

	reset();

	for (int i = 0; i < s.size(); i++) {
		check[s[i] - 65] = 0;
	}

	int sum = 0;
	for (int i = 0; i < 26; i++) {
		sum += check[i];
	}

	cout << sum << "\n";

}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solution();
	}
}