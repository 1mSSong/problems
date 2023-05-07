#include <iostream>
#include <string>
using namespace std;

int main() {
	int i = 666;
	int series = 0;
	string target;

	int n;
	cin >> n;
	while (1) {
		target = to_string(i);
		for (int j = 0; j < target.length() - 2; j++)
			if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6') {
				series++;
				if (series == n) {
					cout << i;
					return 0;
				}
				break;
			}
		i++;
	}
}