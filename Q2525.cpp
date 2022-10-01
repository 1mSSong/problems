#include <iostream>
#include <vector>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B; 
	pair<int, int> current;
	current = make_pair(A, B);
	
	cin >> C;
	pair<int, int> time;
	time.first = C / 60;
	time.second = C % 60;

	pair<int, int> result;

	result.second = time.second + current.second;
	if (result.second >= 60) {
		result.second %= 60;
		result.first = 1;
	}

	result.first += time.first + current.first;
	if (result.first >= 24) {
		result.first %= 24;
	}
	cout << result.first << " " << result.second;

}