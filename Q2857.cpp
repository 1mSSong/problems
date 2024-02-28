#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s[5];
vector<int> res;

void solution() {
	for (int i = 0; i < 5; i++) {
		int index = s[i].find("FBI", 0);

		if (index != -1)
			res.push_back(i + 1);

	}
}

int main() {
	
	
	for (int i = 0; i < 5; i++) {
		cin >> s[i];
	}

	solution();

	if (res.empty()) {
		cout << "HE GOT AWAY!";
	}
	else {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
	}
}