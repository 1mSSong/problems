#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> res(n + 1);
	res[1] = 1;
	res[2] = 2;
	for (int i = 3; i <= n; i++) {
		res[i] = (res[i - 1] + res[i - 2]) % 15746;
	}
	cout << res[n];
}