#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	vector<int> num;
	for (int i = 1; i <= n; i++) {
		num.push_back(i);
	}

	int idx = (k - 1)% n;
	vector<int> res;
	while (n > 0) {
		res.push_back(num[idx]);
		num.erase(num.begin() + idx);
		n--;
		if (n <= 0) break;
		idx = (idx + k - 1) % n;
		
	}
	cout << "<";
	for (int i = 0; i < res.size() - 1; i++) {
		cout << res[i] << ", ";
	}
	cout << res[res.size() - 1] << ">";
}