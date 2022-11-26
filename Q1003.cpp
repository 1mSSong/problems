#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int fib[41] = { 0, 1, 1 };
	for (int i = 3; i < 41; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		
		if (n == 0) {
			cout << "1 0\n";
		}
		else {
			cout << fib[n - 1] << " " << fib[n] << "\n";
		}
	}
}