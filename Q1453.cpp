#include <iostream>
using namespace std;

int chk[101];
int res;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		if (chk[n] == 0)
			chk[n] = 1;
		else
			res++;
	}

	cout << res;
}