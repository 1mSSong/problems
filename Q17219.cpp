#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string id, pw;
	map<string, string> idpw;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> id >> pw;
		idpw[id] = pw;
	}
	for (int i = 0; i < m; i++) {
		cin >> id;
		cout << idpw[id] << "\n";
	}
}