#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long> gas(n);
	vector<long> dis(n - 1);

	for (int i = 0; i < n - 1; i++) {
		cin >> dis[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> gas[i];
	}
	
	int min = gas[0];
	long long cost = gas[0] * dis[0];
	
	for (int i = 1; i < n - 1; i++) {
		if (min > gas[i]) min = gas[i];
		cost += min * dis[i];
	}
	cout << cost;
}