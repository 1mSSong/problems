#include <iostream>
using namespace std;

void solution(string s) {
	int res = 1;
	int tmp = 1;

	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) {
			tmp++;
		}
		else {
			if (res < tmp)
				res = tmp;

			tmp = 1;
		}
	}

	res = max(tmp, res);
	
	cout << res << endl;
}

int main() {
	string s;
	
	for (int i = 0; i < 3; i++) {
		cin >> s;

		solution(s);
	}
}