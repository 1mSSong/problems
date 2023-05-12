#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	
	for (int i = 0; i < str.length(); i++) {
		int tmp = (int)str[i];
		
		if (tmp >= 65 && tmp <= (65 + 26)) {
			tmp += 13;
			tmp -= 65;
			tmp %= 26;

			str[i] = (char)(tmp + 65);
		}
		else if (tmp >= 97 && tmp <= (97 + 26)) { 
			tmp += 13;
			tmp -= 97;
			tmp %= 26;

			str[i] = (char)(tmp + 97);
		}

	}

	cout << str;

	
}