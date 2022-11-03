#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int A[5000001];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);
	cout << A[K - 1];
}