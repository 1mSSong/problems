#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> res(1001);
	res[1] = 1;
	res[2] = 2;
	for (int i = 3; i <= n; i++) {
		res[i] = (res[i - 1] + res[i - 2]) % 10007;
	}
	cout << res[n];
}