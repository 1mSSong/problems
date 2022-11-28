#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> res(1001);
	res[0] = 0;
	res[1] = 1;
	res[2] = 3; 
	res[3] = 5;

	int n;
	cin >> n;
	for (int i = 4; i <= n; i++)
	{
		res[i] = (res[i - 1] + res[i - 2] * 2) % 10007;
	}
	cout << res[n];
}