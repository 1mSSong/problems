#include <iostream>
#include <string>
using namespace std;

int x[8] = {2, 2, -2, -2, 1, 1, -1, -1 };
int y[8] = { -1, 1, -1, 1, 2, -2, 2, -2 };

int main() {
	string input;
	cin >> input;

	int answer = 0;

	int row, col;
	row = input[1] - '0';
	col = input[0] - '0' - 48;



	for (int i = 0; i < 8; i++) {
		int nowx = col;
		int nowy = row;

		nowy += y[i];
		nowx += x[i];

		if (nowx <= 8 && nowx >= 1) {
			if (nowy <= 8 && nowy >= 1)
				answer++;
		}
	}
	
	cout << answer;
}