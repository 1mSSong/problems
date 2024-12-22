#include <iostream>
#include <vector>
using namespace std;

int n, d, k, c;
int type; // 몇 종류

int answer;

vector<int> arr; // 초밥 순서
vector<int> dat; // 초밥 종류 카운트

void input() {

	cin >> n >> d >> k >> c;

	dat.resize(d + 1);
	arr.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

void solution() {
	int sindex = 0, eindex = k - 1;
	dat[c]++;
	type++;

	for (int i = 0; i < k; ++i) {

		int now = arr[i]; // 현재 초밥 번호
		
		// 처음 나오는 초밥 -> 종류++
		if (dat[now] == 0) {
			type++;
		}

		dat[now]++;
	}

	answer = type;
	
	while (1) {
		
		// 제일 앞에 있는 초밥 지우기
		dat[arr[sindex]]--;
		if (dat[arr[sindex]] == 0)
			type--;


		sindex = (sindex + 1) % n;
		eindex = (eindex + 1) % n;

		if (dat[arr[eindex]] == 0)
			type++;
		

		dat[arr[eindex]]++;

		answer = max(answer, type);

		// 처음으로 돌아옴
		if (sindex == 0)
			break;

	}

	cout << answer;
}

int main() {

	input();

	solution();

}