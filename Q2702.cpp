#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solution() {
	int a, b;
	cin >> a >> b;
	if (a < b)
		swap(a, b);

	int res[2] = { 0, 0 };
	res[1] = gcd(a, b);
	res[0] = gcd(a, b) * (a / res[1]) * (b / res[1]);

	cout << res[0] << " " << res[1] << "\n";
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solution();
	}
}