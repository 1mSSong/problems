#include <iostream>
#include <string>
using namespace std;

int main() {
	string s[5];

	int len = 0;

	for (int i = 0; i < 5; i++) {
		cin >> s[i];
		
		if (s[i].size() > len)
			len = s[i].size();
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; s[i].size() != len; j++) {
			s[i] += ";";
		}
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			if (s[j][i] != ';')
				cout << s[j][i];
		}
	}
}