#include <iostream>
#include <vector>
#include <istream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	string tmp;
	getline(cin, tmp);
	t = stoi(tmp);

	for (int i = 0; i < t; i++) {
		string s;
		getline(cin, s);
		
		double res = atof(&s[0]);

		for(int j=0; j<s.length(); j++) {
			
			if (s[j] == '@') res *= 3;
			else if (s[j] == '%') res += 5;
			else if (s[j] == '#') res -= 7;
			else;
		}
		
		cout << fixed;
		cout.precision(2);
		cout << res << "\n";
		
	}
}