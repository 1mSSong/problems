#include <iostream>
#include <vector>
using namespace std;

long long solution(int n, int m);
int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		cout << solution(n, m) << "\n";
	}
	

}

long long solution(int n, int m) {
	long long answer = 1;
	if (n > m) {
		int tmp = n;
		n = m;
		m = tmp;
	}

	for (int i = 0; i < n; i++) {
		answer *= (m - i);
		answer /= (i + 1);
	}
	return answer;
}