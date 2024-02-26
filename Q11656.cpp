#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	vector<string> subs;

	for (int i = 0; i < s.size(); i++) {
		subs.push_back(s.substr(i));
	}

	sort(subs.begin(), subs.end());

	for (int i = 0; i < subs.size(); i++) {
		cout << subs[i] << "\n";
	}
}