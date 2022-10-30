#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<string> word(N);
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}

	sort(word.begin(), word.end(), compare);

	cout << word[0] << "\n";
	for (int i = 1; i < N; i++) {
		if (word[i] == word[i - 1]) {
			continue;
		}
		cout << word[i] << "\n";
	}
}