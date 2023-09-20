#include <iostream>
#include <string>
using namespace std;

bool check(int h, int m, int s) {
	// h는 0 ~ 23 : 십의 자리수가 3일수는 없음
	if (h % 10 == 3)
		return true;
	
	// m의 경우 십의 자리수랑 일의 자리수 모두 가능
	if (m % 10 == 3 || m / 10 == 3)
		return true;

	// s의 경우 십의 자리수랑 일의 자리수 모드 가능

	if (s % 10 == 3 || s / 10 == 3)
		return true;
	
	return false;

}
int main() {
	int n;
	cin >> n;
	
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 59; j++) {
			for (int k = 0; k <= 59; k++) {
				string str = " " + i + j + k;
				if (check(i, j, k)) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
}