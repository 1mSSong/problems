#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string s1, s2;

	cin >> s1 >> s2;

	int res = 0;
	if (n % 2 == 0) {
		if (s1 == s2)
			res = 0;

		else
			res = 1;
	}

	else {
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == s2[i]) {
				res = 1;
				break;
			}
			res = 0;
		}
	}

	if (!res) {
		cout << "Deletion succeeded";
	}
	else {
		cout << "Deletion failed";
	}
}