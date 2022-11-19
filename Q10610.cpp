#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	string n;
	cin >> n;
	bool chk = false;
	int sumNum = 0;
	for (int i = 0; i < n.length(); i++) {
		if (n[i] == '0') chk = true;
		sumNum += (n[i] - '0');
	}
	
	if ((!chk) || (sumNum%3)) {
		cout << "-1";
		return 0;
	}
	
	vector<int> num(n.length());
	for (int i = 0; i < n.length(); i++) {
		num[i] = (n[i] - '0');
	}
	sort(num.begin(), num.end(), compare);
	
	for (int i = 0; i < n.length(); i++) {
		cout << num[i];
	}
}