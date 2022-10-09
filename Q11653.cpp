#include <iostream>
#include <vector>
using namespace std;

void isPrime(int N, vector<int>& prime);

int main() {
	int N;
	vector<int> prime;
	cin >> N;
	isPrime(N, prime);
	if (N == 1) return 0;
	

	int i = 0;
	while (N != 1) {
		
		if ((N % prime[i]) == 0) {
		
			cout << prime[i] << endl;
			N /= prime[i];
		}
		else {
			i++;
		}
	}

}

void isPrime(int N, vector<int>& prime) {
	for (int i = 2; i <= N; i++) {
		int cnt = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		
		prime.push_back(i);
	}
}