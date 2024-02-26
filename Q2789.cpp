#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	string res = "";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'C')
			continue;
		if (s[i] == 'A')
			continue;
		if (s[i] == 'M')
			continue;
		if (s[i] == 'B')
			continue;
		if (s[i] == 'R')
			continue;
		if (s[i] == 'I')
			continue;
		if (s[i] == 'D')
			continue;
		if (s[i] == 'G')
			continue;
		if (s[i] == 'E')
			continue;

		res += s[i];
	}

	cout << res;
}