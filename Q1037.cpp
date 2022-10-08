#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> prime;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		prime.push_back(a);
	}
	sort(prime.begin(), prime.end());
	if (N != 1) {
		cout << prime[0] * prime[N - 1];
	}
	else
		cout << prime[0] * prime[0];
}