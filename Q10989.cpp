#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, tmp;
	int count[10001] = { 0 };
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		count[tmp]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << i << "\n";
		}
	}
}