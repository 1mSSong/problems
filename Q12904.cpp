#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

string s, t;
unordered_map<string, int> chk; // visited  역할

void input() {
	cin >> s >> t;
}

string reverse(string str) {

	for (int i = 0; i < str.length() / 2; ++i) {
		swap(str[i], str[str.length() - 1 - i]);
	}

	return str;
}

void solution() {

	while (1) {

		if (t.length() < s.length())
			break;

		if (t == s) {
			cout << 1;
			return;
		}
		
		int t_len = t.length();
		
		// 끝이 A
		if (t[t_len - 1] == 'A') {
			t = t.substr(0, t_len - 1);
		}
		// 끝이 B
		else {
			t = t.substr(0, t_len - 1);
			t = reverse(t);
		}
	}

	cout << 0;
	return;
}
int main() {

	input();

	solution();

}