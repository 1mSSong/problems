#include <iostream>
#include <string>
using namespace std;

int main() {
	int x, y;
	int date[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string days[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	cin >> x >> y;
	int total = 0;
	for (int i = 0; i < x; i++) {
		total += date[i];
	}
	total += y;
	total %= 7;
	cout << days[total];

}