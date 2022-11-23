#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) return false;
	int cnt = 0;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) cnt++;
	}
	if (cnt == 0) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n != 0) {
		int half = n / 2;
		bool ischeck = false;

		for (int i = half - 2; i >= 0; i--) {
			if (isPrime(half - i) && isPrime(half + i)) {
				cout << n << " = " << half - i << " + " << half + i << "\n";
				ischeck = true;
				break;
			}
		}

		if (!ischeck) cout << "Goldbach's conjecture is wrong" << "\n";
		cin >> n;
	}
}
