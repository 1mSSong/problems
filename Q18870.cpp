#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<long long> num1;
	vector<long long> num2;


	for (int i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		num1.push_back(tmp);
		num2.push_back(tmp);
	}

	sort(num2.begin(), num2.end());
	num2.erase(unique(num2.begin(), num2.end()), num2.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(num2.begin(), num2.end(), num1[i]) - num2.begin() << " ";
	}
}