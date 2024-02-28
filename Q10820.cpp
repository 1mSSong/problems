#include <iostream>
#include <string>
using namespace std;

void solution(string s) {
	int res[4] = { 0, };

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			res[0]++;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			res[1]++;
		else if (s[i] == ' ')
			res[3]++;
		else
			res[2]++;
	}

	cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << "\n";
}

int main() {
	string s;
	
	while (getline(cin, s)) {
		solution(s);
	}
}