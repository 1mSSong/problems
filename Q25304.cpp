#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int N = s.length();
	vector<int> num;
	for (int i = 0; i < N; i++) {
		num[i] = (int)(s[i] - 65);
		cout << num[i] << endl;

	}
	
}