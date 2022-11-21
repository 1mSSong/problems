#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool isSquare(int n);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;

	vector<int> square;
	int sum = 0;

	for (int i = m; i <= n; i++) {
		if (isSquare(i)) {
			sum += i;
			square.push_back(i);
		}
	}
	if (square.size() == 0) {
		cout << "-1";
		return 0;
	}
	cout << sum << "\n" << square[0];

}

bool isSquare(int n) {
	for (int i = sqrt(n) - 1; i <= sqrt(n) + 1; i++) {
		if (n == i * i) {
			return true;
		}
	}
	return false;
}