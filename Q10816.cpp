#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	
	sort(num.begin(), num.end());
	
	cin >> M;
	int card;
	for (int i = 0; i < M; i++) {
		cin >> card;
		cout << upper_bound(num.begin(), num.end(), card) - lower_bound(num.begin(), num.end(), card) << " ";
	}
}