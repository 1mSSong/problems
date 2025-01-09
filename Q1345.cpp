#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double low = 21e8;
double high = -21e8;

int n;
int a0;

double answer;
int sum;

void solution(int s, int i) {
	
	if (answer == -1)
		return;

	double now_low = (s - a0) / (double(i + 1));
	double now_high = (s - a0 + 1) / (double(i + 1));

	
	if (i == 0) {
		low = now_low;
		high = now_high;

		return;
	}

	if (now_low >= high) {
		answer = -1;
		return;
	}

	if (now_high <= low) {
		answer = -1;
		return;
	}

	low = max(low, now_low);
	high = min(high, now_high);
	
}

void input() {
	
	cin >> n >> a0;

	for (int i = 0; i < n; ++i) {
		
		int s;
		cin >> s;


		solution(s, i);
		
	}
}

void chkanswer() {

	if (n == 0) {
		cout << "0.0";
		return;
	}

	if (answer == -1) {
		cout << answer;
		return;
	}

	if (high <= 0 || low < 0) {
		cout << -1;
		return;
	}
	
	cout << fixed;
	cout.precision(9);

	cout << low;
}

int main() {


	input();
	
	chkanswer();
	
}