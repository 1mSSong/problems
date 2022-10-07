#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b);
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[i] = a;
	}

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		B[i] = a;
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), compare);

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}
	cout << sum;
}

bool compare(int a, int b) {
	return a > b;
}

