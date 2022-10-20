#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int count = 0;
	for (int i = 2; i <= N; i++) {
		if (i % 5 == 0) count++;
		if (i % 25 == 0) count++;
		if (i % 125 == 0)count++;
	}
	cout << count;
}
