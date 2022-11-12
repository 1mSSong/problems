#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		long long data = pow(a, b);
		cout << data % b << "\n";
	}
}