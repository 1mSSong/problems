#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	int M, idx;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> idx;
		int result = upper_bound(num.begin(), num.end(), idx) -
			lower_bound(num.begin(), num.end(), idx);
		if (result != 0) cout << "1\n";
		else cout << "0\n";
	}
}