#include <iostream>
#include <vector>
using namespace std;

int n, d, k, c;
int answer;
int tmp_answer;

int DAT[3001]; // index: �ʹ� ����, value: ����
vector<int> sushi; // �ʹ� ��ġ

void input() {
	cin >> n >> d >> k >> c;
	
	sushi.resize(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> sushi[i];
	}
}

void solution() {

	// ���� �ʹ�
	DAT[c]++;
	tmp_answer++;

	int s = 0, e = k - 1;
	
	// ó�� �ʹ� k�� 
	for (int i = 0; i < k; ++i) {
		int now = sushi[i];

		// ���ο� �ʹ� �߰�
		if (DAT[now] == 0)
			tmp_answer++;

		DAT[now]++;
	}

	answer = max(answer, tmp_answer);
	
	// �̵�
	while (1) {
		// s �ʹ� ����
		int s_now = sushi[s];
		DAT[s_now]--;
		if (DAT[s_now] == 0)
			tmp_answer--;

		// s, e �̵�
		s = (s + 1) % n;
		e = (e + 1) % n;

		if (s == 0)
			break;

		// e �ʹ� �߰�
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