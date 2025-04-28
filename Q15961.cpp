#include <iostream>
#include <vector>
using namespace std;

int n, d, k, c;
int answer;
int tmp_answer;

int DAT[3001]; // index: 초밥 종류, value: 개수
vector<int> sushi; // 초밥 위치

void input() {
	cin >> n >> d >> k >> c;
	
	sushi.resize(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> sushi[i];
	}
}

void solution() {

	// 쿠폰 초밥
	DAT[c]++;
	tmp_answer++;

	int s = 0, e = k - 1;
	
	// 처음 초밥 k개 
	for (int i = 0; i < k; ++i) {
		int now = sushi[i];

		// 새로운 초밥 추가
		if (DAT[now] == 0)
			tmp_answer++;

		DAT[now]++;
	}

	answer = max(answer, tmp_answer);
	
	// 이동
	while (1) {
		// s 초밥 제거
		int s_now = sushi[s];
		DAT[s_now]--;
		if (DAT[s_now] == 0)
			tmp_answer--;

		// s, e 이동
		s = (s + 1) % n;
		e = (e + 1) % n;

		if (s == 0)
			break;

		// e 초밥 추가
		int e_now = sushi[e];
		if (DAT[e_now] == 0)
			tmp_answer++;
		DAT[e_now]++;

		answer = max(answer, tmp_answer);
	}
}

int main() {

	input();

	solution();
	
	cout << answer;
}