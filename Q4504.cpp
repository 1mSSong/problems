#include <iostream>
using namespace std;

int n;

void solution(int num) {
	if (num % n != 0)
		cout << num << " is NOT a multiple of " << n << ".\n";
	else
		cout << num << " is a multiple of " << n << ".\n";
}
int main() {
	cin >> n;

	int num;
	cin >> num;

	while (num != 0) {
		solution(num);
		
		cin >> num;
	}
}