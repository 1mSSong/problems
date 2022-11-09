#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> S(21);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		if (s == "add") {
			int a;
			cin >> a;
			S[a] = 1;
		}
		else if (s == "remove") {
			int a;
			cin >> a;
			S[a] = 0;
		}
		else if (s == "check") {
			int a;
			cin >> a;
			if (S[a] == 1) cout << "1\n";
			else cout << "0\n";
		}
		else if (s == "toggle") {
			int a;
			cin >> a;
			if (S[a] == 1) S[a] = 0;
			else S[a] = 1;
		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++) {
				S[i] = 1;
			}
		}
		else {
			for (int i = 1; i <= 20; i++) {
				S[i] = 0;
			}
		}
	}
}