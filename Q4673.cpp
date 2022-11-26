#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int d(int n) {
	string num = to_string(n);
	int res = n;
	
	for (int i = 0; i < num.length(); i++) {
		res += (num[i] - '0');
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> chk(10101);

	for (int i = 1; i <= 10000; i++) {
		if (i != d(i)) {
			chk[d(i)] = 1;
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (chk[i] != 1) {
			cout << i << "\n";
		}
	}
}