#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int K;
	cin >> K;
	vector<vector<int>> st(K);

	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			st[i].push_back(b);
		}
		sort(st[i].begin(), st[i].end());
	}
	vector<vector<int>> gap(K);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < st[i].size() - 1; j++) {
			int a = st[i][j + 1] - st[i][j];
			gap[i].push_back(a);
		}
		sort(gap[i].begin(), gap[i].end());
	}

	for (int i = 0; i < K; i++) {
		cout << "Class " << i + 1 << "\n";
		cout << "Max " << st[i][st[i].size() - 1] << ", Min " << st[i][0]
			<< ", Largest gap " << gap[i][gap[i].size() - 1];
		cout << "\n";
	}
	

}