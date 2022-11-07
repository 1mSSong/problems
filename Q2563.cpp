#include <iostream>
using namespace std;

int a[100][100];
int main() {
	int x, y;
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		for (int j = y + 1; j <= y + 10; j++) {
			for (int k = x + 1; k <= x + 10; k++) {
				if (a[k][j] != 1) {
					cnt++;
					a[k][j] = 1;
				}
			}
		}
	}

	cout << cnt;
}