#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> m;

	map<int, int> input;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		input[a] = 1;
	}
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (input[a] == 1) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}
}