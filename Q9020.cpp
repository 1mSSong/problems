#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

bool isPrime(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int i = n / 2; i >= 2; i--) {
			if (isPrime(i) && isPrime(n - i)) {
				cout << i << " " << n - i << "\n";
				break;
			}
		}
	}
}


bool isPrime(int n) {
	int cnt = 0;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			cnt++;
		}
	}
	if (cnt == 0) return true;
	else return false;
	
}