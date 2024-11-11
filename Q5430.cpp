#include <iostream>
#include <deque>
#include <string>
using namespace std;

int t;

int n;
deque<int> arr;

string command;
string str;

int flag;

void init() {
	arr.clear();
	flag = 0;
}

void input() {
	cin >> command;

	cin >> n;

	cin >> str;

	int a = 0, b = 0;
	while (1) {

		if (str.length() == 2)
			break;

		string tmp;

		b = str.find(',', a);

		if (b == -1) {
			if (a == 0) {
				tmp = str.substr(1);
			}
			else {
				tmp = str.substr(a);
			}
			
			tmp = tmp.substr(0, tmp.length() - 1);
			arr.push_back(stoi(tmp));

			break;
		}


		if (a == 0) {
			tmp = str.substr(1, b - a - 1);
		}
		else {
			tmp = str.substr(a, b - a);
		}

		a = b + 1;
		arr.push_back(stoi(tmp));
	}
}

void solution() {

	for (int i = 0; i < command.length(); ++i) {

		if (command[i] == 'D') {

			if (arr.empty()) {
				flag = -1;
				break;
			}

			if (flag) {
				arr.pop_back();
			}
			
			else {
				arr.pop_front();
			}
		}

		else if (command[i] == 'R') {
			flag = (flag + 1) % 2;
		}
	}

	if (flag == -1) {
		cout << "error\n";
		return;
	}

	if (arr.empty()) {
		cout << "[]\n";
		return;
	}

	cout << "[";
	
	
	// 뒤에서부터
	if (flag) {
		while (arr.size() != 1) {
			cout << arr.back() << ",";
			arr.pop_back();
		}

		cout << arr.back();
		cout << "]\n";
	}

	else {
		while (arr.size() != 1) {
			cout << arr.front() << ",";
			arr.pop_front();
		}

		cout << arr.front();
		cout << "]\n";
	}
}

int main() {
	cin >> t;

	for (int i = 0; i < t; ++i) {
		init();

		input();

		solution();

	}
}