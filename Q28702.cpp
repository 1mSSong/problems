#include <iostream>
#include <string>
using namespace std;

string arr[3];

int order;
int num;

void input() {
	for (int i = 0; i < 3; ++i) {
		cin >> arr[i];
	}
}

void chk() {

	for (int i = 0; i < 3; ++i) {
		if (arr[i][0] >= '0' && arr[i][0] <= '9') {
			order = i;
			num = stoi(arr[i]);
			return;
		}
	}
}

int main() {
	input();

	chk();

	int answer = num + (3 - order);

	if (answer % 3 == 0 && answer % 5 == 0)
		cout << "FizzBuzz";

	else if (answer % 3 == 0 && answer % 5 != 0)
		cout << "Fizz";

	else if (answer % 3 != 0 && answer % 5 == 0)
		cout << "Buzz";

	else
		cout << answer;

	
}

