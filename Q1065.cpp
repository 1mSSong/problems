#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int countHan(int X);

int main() {
	int X;
	cin >> X;
	 
	if (X < 100) {
		cout << X;
		return 0;
	}
	
	cout<< 99 + countHan(X);

}

int countHan(int X) {
	int cnt = 0;
	for (int i = 100; i <= X; i++) {
		string a = to_string(i);
		
		int d = (a[0] - '0') - (a[1] - '0');

		for (int j = 1; j < a.length() - 1; j++) {
			if ((a[j] - '0') - (a[j + 1] - '0') != d) {
				break;
			}
			cnt++;
		}
	}
	return cnt;
}