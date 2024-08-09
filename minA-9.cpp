#include <iostream>
#include <vector>
using namespace std;

int t;
int n;
long long ans;

vector<int> arr;
int path[5];

void init() {
	arr.clear();

	ans = 0;
}

void input() {
	cin >> n;
	
	arr.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

void func(int now) {
	if (now >= 4) {
		if (path[0] == 0 && path[3] == n - 1)
			return;


		long long tmp1 = (arr[path[0]] + arr[path[3]]) * (arr[path[0]] + arr[path[3]]) 
			+ (arr[path[1]] + arr[path[2]]) * (arr[path[1]] + arr[path[2]]);

		long long tmp2 = (arr[path[0]] + arr[path[1]]) * (arr[path[0]] + arr[path[1]])
			+ (arr[path[2]] + arr[path[3]]) * (arr[path[2]] + arr[path[3]]);

		ans = max(ans, max(tmp1, tmp2));

		return;
	}

	for (int i = 0; i < n; ++i) {

		if (now > 0 && i <= path[now - 1])
			continue;

		if (now > 0 && (i - path[now - 1]) <= 1)
			continue;

		path[now] = i;

		func(now + 1);
		
		path[now] = 0;
	}
}


int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		func(0);

		cout << "#" << tc << " " << ans << "\n";
	}
}