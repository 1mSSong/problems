#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		if (i == 0) {
			for (int j = 0; j < (n - i - 1); j++)
				cout << " ";
			cout << "*\n";
		}

		else if (i == (n - 1)) {
			for (int j = 0; j < 2 * i + 1; j++)
				cout << "*";
		}

		else {
			
			for (int j = 0; j < (n - i - 1); j++)
				cout << " ";
			cout << "*";

			for (int j = 0; j < 2 * i - 1; j++)
				cout << " ";
			cout << "*\n";
		}
	}
}