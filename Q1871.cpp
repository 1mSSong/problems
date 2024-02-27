#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void solution() {
	string s;
	vector<string> tmp;
	
	cin >> s;

	istringstream iss(s);
	char del = '-';
	string token;
	while (getline(iss, token, del)) {
		tmp.push_back(token);
	}

	int n1 = (tmp[0][0] - 'A') * 26 * 26 + (tmp[0][1] - 'A') * 26 + (tmp[0][2] - 'A');
	int n2 = stoi(tmp[1]);

	if (abs(n1 - n2) <= 100)
		cout << "nice\n";
	else
		cout << "not nice\n";
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solution();
	}
	
}