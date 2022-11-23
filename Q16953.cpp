#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	string sb = to_string(b);
	int res = 0;
	while (b != a) {

		if (b < a) {
			cout << "-1";
			return 0;
		}

		if(sb[sb.length() -1]=='1') {
			res++;
			sb = sb.substr(0, sb.length() - 1);
			b = stoi(sb);
		}
		else if (b % 2 == 0) {
			res++;
			b = b / 2;
			sb = to_string(b);
		}
		else {
			cout << "-1";
			return 0;
		}
	}
	cout << res + 1;
}