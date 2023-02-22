#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<string> parse;
	vector<string> sign;

	int i = 0;
	while (s.length() != 0) {
		if (i == s.length()) {
			parse.push_back(s.substr(0, i));
			break;
		}
		if (s[i] == '+') {
			parse.push_back(s.substr(0, i));
			sign.push_back("+");
			s = s.substr(i + 1);
			i = 0;
		}
		else if (s[i] == '-') {
			parse.push_back(s.substr(0, i));
			sign.push_back("-");
			s = s.substr(i + 1);
			i = 0;
		}
		else {
			i++;
		}
	}

	int answer = stoi(parse[0]);
	bool chk = true;
	for (int i = 0; i < sign.size(); i++) {
		if (chk == false) {
			sign[i] = "-";
		}

		if (sign[i] == "-") {
			answer -= stoi(parse[i + 1]);
			chk = false;
		}
		else {
			answer += stoi(parse[i + 1]);
		}
	}
	cout << answer;
}