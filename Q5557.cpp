#include <iostream>
#include <vector>
using namespace std;

int n;
int result;
vector<int> num;

void input() {
	cin >> n;
	num.resize(n - 1);

	for (int i = 0; i < n - 1; ++i) {
		cin >> num[i];
	}

	cin >> result;
}

void solution() {
	
	vector<long long> prev(21);
	vector<long long> now(21);

	prev[num[0]] = 1;

	for (int i = 1; i < n - 1; ++i) {
		
		for (int j = 0; j <= 20; ++j) {
			
			if (prev[j] == 0)
				continue;
			
			long long tmp[2] = { j + num[i], j - num[i] };
			for (int i = 0; i < 2; ++i) {

				if (tmp[i] < 0 || tmp[i] > 20)
					continue;

				now[tmp[i]] += prev[j];

			}
		}

		prev = now;
		now.clear();
		now.resize(21);
	}

	cout << prev[result];
}

int main() {

	input();

	solution();
}
