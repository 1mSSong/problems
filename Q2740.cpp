#include <iostream>
#include <vector>
using namespace std;

int A[101][101];
int B[101][101];
int res[101][101];

int main() {
	int N, M, K;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	cin >> M >> K;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				res[i][j] += A[i][k] * B[k][j];
			}
			cout << res[i][j] << " ";
		}
		cout << endl;
	}


}