#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	char op;
	cin >> a >> op >> b;

	int a1 = a.length() - 1;
	int b1 = b.length() - 1;

	if (op == '*') {
		cout << "1";
		for (int i = 0; i < (a1 + b1); i++) {
			cout << "0";
		}
		return 0;
	}

	if (a1 == b1) {
		cout << "2";
		for (int i = 0; i < a1; i++) {
			cout << "0";
		}
		return 0;
	}

	if (a1 > b1) {
		a[a1 - b1] = '1';
		cout << a;
	}
	else {
		b[b1 - a1] = '1';
		cout << b;
	}
} 