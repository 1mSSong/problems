#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int r1;
	cin >> r1;

	for (int i = 0; i < n - 1; i++) {
		int r;
		cin >> r;
		int g = gcd(r1, r);

		cout << r1 / g << "/" << r / g << "\n";
	}
}