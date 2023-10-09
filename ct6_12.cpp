#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> a, b;

bool compare(int x, int y) {
	return x > y; 
}
int main() {
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	for (int i = 0; i < k; i++) {
		// A의 원소가 B의 원소보다 작을 때만 바꾸기 
		if (a[i] < b[i]) swap(a[i], b[i]);
		else break;
	}

	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i];
	}

	cout << res;

}