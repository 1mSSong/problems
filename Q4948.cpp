#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void countPrime();
bool isPrime(int n);
vector<int> cntPrime(123456 * 2 + 1);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	countPrime();
	cin >> n;

	while (n != 0) {
		cout << (cntPrime[2 * n] - cntPrime[n]) << "\n";
		cin >> n;
	}
}

bool isPrime(int n) {
	int cnt = 0;
	for (int i = 2; i < (int)(sqrt(n)) + 1; i++) {

		if (n % i == 0) cnt++;
	}
	if (cnt == 0) return true;
	else return false;
}

void countPrime() {
	cntPrime[0] = 0;
	cntPrime[1] = 0;
	cntPrime[2] = 1;
	
	for (int i = 3; i <= 123456 * 2; i++) {
		if (isPrime(i)) {
			cntPrime[i] = cntPrime[i - 1] + 1;
		}
		else {
			cntPrime[i] = cntPrime[i - 1];
		}
	}
}