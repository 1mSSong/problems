#include <iostream>
using namespace std;


long long P[101];
void makeP() {
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	P[6] = 3;
	for (int i = 7; i < 101; i++) {
		P[i] = P[i - 5] + P[i - 1];
		//P[i]=P[i-3]+P[i-2]
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	makeP();

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << P[n] << "\n";
	}
}