#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
int main() {
	int A, B;
	cin >> A >> B;

	int cnt = 1;

	for (int i = 0; i < 1001;) {
		for (int j = 0; j < cnt; j++) {
			arr[i++] = cnt;
		}
		cnt++;
	}
	int ans = 0;
	for (int i = A - 1; i < B; i++) {
		ans += arr[i];
	}
	cout << ans;
}


