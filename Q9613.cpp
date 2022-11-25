#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		
		vector<int> num(n);
		for (int j = 0; j < n; j++) {
			cin >> num[j];
		}
		
		long res = 0;
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				res += gcd(num[j], num[k]);
			}
		}

		cout << res << "\n";
	}
}