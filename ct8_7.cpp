#include <iostream>
#include <vector>
using namespace std;

int n;
int d[10001];

int main() {
	cin >> n;

	d[1] = 1;
	d[2] = 3;

	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2] * 2) % 796796;
	}

	cout << d[n];
}