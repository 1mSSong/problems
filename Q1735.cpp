#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b)
		swap(a, b);

	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int main() {
	long long a1, b1, a2, b2;

	cin >> a1 >> b1;
	cin >> a2 >> b2;

	long long res1, res2;
	res2 = b1 * b2;
	res1 = b1 * a2 + b2 * a1;

	long long gcds = gcd(res1, res2);
	while (gcds != 1) {
		res2 /= gcds;
		res1 /= gcds;

		gcds = gcd(res1, res2);
	}

	cout << res1 << " " << res2;

}