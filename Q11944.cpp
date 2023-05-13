#include <iostream>
#include <string>
using namespace std;

int main() {
	string tmpN;
	int n, m;
	cin >> tmpN >> m;

	int len = tmpN.length();
	n = stoi(tmpN);

	if (n * len <= m) {
		for (int i = 0; i < n; i++) {
			cout << n;
		}
	}
	else {
		for (int i = 0; i < (m / len); i++) {
			cout << n;
		}
		for (int i = 0; i < (m % len); i++) {
			cout << tmpN[i];
		}
	}


}