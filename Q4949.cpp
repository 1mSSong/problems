#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;

	while (1) {

		getline(cin, str);

		stack<char> s;

		if (str == ".")
			break;


		int len = str.length();

		int flag = 0;

		for (int i = 0; i < len; ++i) {
			if (str[i] == '(') {
				s.push('(');
			}

			else if (str[i] == ')') {
				if (s.empty()) {
					flag = 1;
					break;
				}

				if (s.top() == '(')
					s.pop();
				else {
					flag = 1;
					break;
				}
			}

			else if (str[i] == '[')
				s.push('[');

			else if (str[i] == ']') {
				if (s.empty()) {
					flag = 1;
					break;
				}

				if (s.top() == '[') {
					s.pop();
				}
				else {
					flag = 1;
					break;
				}
			}
		}
		
		if (s.size() != 0)
			flag = 1;

		(flag == 0) ? cout << "yes\n" : cout << "no\n";

	}

}