#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int fibonacci(int n, int p = 1, int pp = 0) {
	if (n == 0) {
		return pp;
	}
	else if (n == 1) {
		return p;
	}
	else {
		int cur = p + pp;
		pp = p;
		p = cur;
		return fibonacci(n - 1, p, pp);
	}
}
int main() {
	int n;
	cin >> n;
	cout << fibonacci(n);
}