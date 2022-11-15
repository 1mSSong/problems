#include <iostream>
using namespace std;

int a, b, c;


int arr[21][21][21];

void makeArr() {
	for (int j = 0; j < 21; j++) {
		for (int k = 0; k < 21; k++) {
			arr[0][j][k] = 1;
		}
	}

	for (int j = 0; j < 21; j++) {
		for (int k = 0; k < 21; k++) {
			arr[j][0][k] = 1;
		}
	}

	for (int j = 0; j < 21; j++) {
		for (int k = 0; k < 21; k++) {
			arr[j][k][0] = 1;
		}
	}


	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 21; j++) {
			for (int k = 1; k < 21; k++) {
				if (i < j && j < k)
					arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];

				else
					arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];

			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	makeArr();

	cin >> a >> b >> c;
	while (!(a == -1 && b == -1 && c == -1)) {
		if (a <= 0 || b <= 0 || c <= 0) {
			cout << "w(" << a << ", " << b << ", " << c << ") = 1\n";
		}
		else if (a > 20 || b > 20 || c > 20) {
			cout << "w(" << a << ", " << b << ", " << c << ") = " << arr[20][20][20] << "\n";
		}
		else 
			cout << "w(" << a << ", " << b << ", " << c << ") = " << arr[a][b][c] << "\n";
		cin >> a >> b >> c;
	}
}