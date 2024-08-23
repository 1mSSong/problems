#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int t;
int n, k;

int one;

vector<char> q;
set<int, greater<int>> arr;

void init() {
	one = 0;

	q.clear();
	
	arr.clear();
}

void input() {
	cin >> n >> k;

	one = n / 4;

	string s;
	cin >> s;

	int len = s.length();

	for (int i = 0; i < len; ++i) {
		q.push_back(s[i]);
	}
}

void solution() {

	for (int i = 0; i < 4; ++i) {
		string tmp = "";
		
		for (int j = 0; j< one; ++j) {
			tmp += q[i * one + j];
		}

		int num = stoi(tmp, nullptr, 16);
		arr.insert(num);
	}

	char tmp = q[0];
	q.erase(q.begin());
	q.push_back(tmp);
}

int main() {

	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();
		input();

		for (int j = 0; j < one; ++j) {
			solution();
		}

		auto it = arr.begin();
		advance(it, k - 1);

		cout << "#" << tc << " " << (*it) << "\n";
	}
}