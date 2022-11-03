#include <iostream>
#include <vector>
#include <string>
using namespace std;

string A, B;

int main() {
	string zero = "0";
	cin >> A >> B;
	string tmp;

	if (A.length() < B.length()) {
		tmp = A;
		A = B;
		B = tmp;
	}

	int max = A.length();

	if (A.length() != B.length()) {
		for (int i = 1; i < A.length() - B.length(); i++) {
			zero += '0';
		}
		B = zero + B;
	}
	
	vector<int> res(max + 1);
	int idx = max - 1;
	int residx = max;


	while (residx > 0) {
		int tmp = res[residx] + (A[idx] - '0') + (B[idx] - '0');
		if (tmp >= 10) {
			res[residx - 1] = 1;
		}
		res[residx] = tmp % 10;
		idx--;
		residx--;

	}
	if (res[0] != 0) cout << res[0];
	for (int i = 1; i <= max; i++) {
		cout << res[i];
	}
}