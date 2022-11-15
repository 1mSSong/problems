#include <iostream>
using namespace std;

int arr[41] = { 0 };
int n, cnt1 = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		cnt1++;
		return 1;
	}
	else return (fib(n - 1) + fib(n - 2));
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	fib(n);

	arr[1] = arr[2] = 1;
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << cnt1 << " " << n - 2;
}