#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, h;

vector<int> imos;
vector<int> sum; // index의 장애물 개수

void input() {
	cin >> n >> h;

	imos.resize(h + 1, 0);
	sum.resize(h + 1, 0);
	
	for (int i = 0; i < n / 2;++i) {
		
		int num1, num2;
		cin >> num1 >> num2;

		// 석순
		imos[0]++;
		imos[num1]--;

		// 종유석
		imos[h - num2]++;
		imos[h]--;
		
	}
}

void solution() {
	
	int now = 0;
	for (int i = 0; i < h; ++i) {
		now += imos[i];
		sum[i] = now;
	}

	sum.pop_back();
	
	sort(sum.begin(), sum.end());

	int answer = 1;
	for (int i = 1; i < h; ++i) {
		if (sum[i - 1] == sum[i])
			answer++;
		else
			break;
	}

	cout << sum[0] << " " << answer;
}

int main() {

	input();

	solution();
}