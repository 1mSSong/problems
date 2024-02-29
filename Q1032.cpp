#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> s(n);

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < s[0].size(); i++) {
		char c = s[0][i];
		bool chk = true;

		for (int j = 1; j < n; j++) {
			if (s[j][i] != c) {
				chk = false;
				continue;
			}
		}

		if (chk)
			cout << c;
		else
			cout << "?";
	}
}