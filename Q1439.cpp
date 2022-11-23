#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;

	int res = 0;
	for (int i = 0; i < input.length() - 1; i++) {
		if (input[i] != input[i + 1]) res++;
	}

	cout << (int)((res / 2.0) + 0.5);
}