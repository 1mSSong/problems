#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> coin(N);
	
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		coin[i] = a;
	}
	int sum = 0;
	for (int i = 0; i < N && K>0; i++) {
		if (K / coin[N - i - 1 ] != 0) {
			sum += K / coin[N - i - 1];
			K = K % coin[N - i - 1];
		}
	}
	cout << sum;
}