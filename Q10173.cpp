#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solution(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);

	if (s.find("nemo") != string::npos) {
		cout << "Found\n";
	}
	else {
		cout << "Missing\n";
	}
}

int main() {
	string s;
	getline(cin, s);
	
	while (s != "EOI") {
		solution(s);

		getline(cin, s);
	}
}