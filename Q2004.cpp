#include <iostream>
#include <algorithm>
using namespace std;

long long d2(long long n)
{
	long long cnt = 0;
	for (long long i = 2; i <= n; i *= 2)
		cnt += n / i;
	return cnt;
}

long long d5(long long n)
{
	long long cnt = 0;
	for (long long i = 5; i <= n; i *= 5)
		cnt += n / i;
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	long long five, two;
	
	five = d5(n) - d5(m) - d5(n - m);
	two = d2(n) - d2(m) - d2(n - m);

	cout << min(five, two);
}
