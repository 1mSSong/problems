#include <iostream>
#include <vector>
using namespace std;

void isPrime(int a, int b);

int main() {
	int M, N;
	cin >> M >> N;
	if (M == 1) {
		if (N == 1) {
			cout << "-1";
			return 0;
		}
		else M++;
	}
	isPrime(M, N);
}

void isPrime(int a, int b) {
	vector<int> prime;
	int sum = 0;
	int cnt = 0;
	for (int i = a; i <= b; i++) {
		int primecnt = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				primecnt++;
			}
		}
		if (primecnt == 0) {
			prime.push_back(i);
			sum += prime[cnt];
			cnt++;
		}
		
	}
	if (prime.size() == 0) {
		cout << "-1";
		return;
	}
	cout << sum << endl << prime[0];

}