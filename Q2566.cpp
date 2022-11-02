#include <iostream>
using namespace std;


int main() {
	int A[9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> A[i][j];
		}
	}

	int max = A[0][0];
	pair<int, int> idx;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (max < A[i][j]) {
				max = A[i][j];
				idx.first = i;
				idx.second = j;
			}
		}
	}
	cout << max << "\n" << idx.first + 1 << " " << idx.second + 1;
}