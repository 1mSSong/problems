#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		cin >> s;

		bool chk = true;
		for (int j = 0; j < s.length(); j++) {
			for (int k = 0; k < j; k++) {
				if (s[j] != s[j - 1] && s[j] == s[k]) {
					chk = false;
					break;
				}
			}
		}
		if (chk) cnt++;
	}
	cout << cnt;
}