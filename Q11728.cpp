#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int> A(N);
	vector<int> B(M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}

	int minA = 0;
	int minB = 0;

	while (minA + minB < N + M) {
		
		if (minA == N) {
			printf("%d ", B[minB++]);
		}
		else if (minB == M) {
			printf("%d ", A[minA++]);
		}
		else {
			if (A[minA] < B[minB]) {
				printf("%d ", A[minA++]);			}

			else {
				printf("%d ", B[minB++]);
			}

		}
	}
}