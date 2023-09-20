#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	char moveTypes[4] = { 'L', 'R', 'U', 'D' };
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
	int x = 1, y = 1;

	cin >> n;
	cin.ignore();

	string plan;
	getline(cin, plan);
	 
	for (int i = 0; i < plan.size(); i++) {
		char now = plan[i];
		if (now == ' ')
			continue;

		int nx = -1, ny = -1;

		for (int j = 0; j < 4; j++) {
			if (now == moveTypes[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}

		if (nx < 1 || ny < 1 || nx > n || ny > n)
			continue;

		x = nx;
		y = ny;
	}
	cout << x << ' ' << y << endl;
}