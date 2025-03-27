#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct Info {
	int y;
	int x;
	int nLike; // �α� �����ϴ� ��� ��
	int nEmpty; // �� �ڸ� ��

	bool operator <(Info right) const {

		if (nLike == right.nLike) {

			if (nEmpty == right.nEmpty) {

				if (y == right.y) {
					return x > right.x;
				}
				return y > right.y;
			}
			return nEmpty < right.nEmpty;
		}
		return nLike < right.nLike;
	}
};

int n;

vector<unordered_map<int, int>> like; // �����ϴ� ���
vector<int> order; // ����
vector<vector<int>> confirm; // Ȯ���� �ο�

int score[5] = { 0, 1, 10, 100, 1000 };
int answer;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void input() {
	cin >> n;

	like.resize(n * n + 1);
	order.resize(n * n);
	confirm.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n * n; ++i) {
		cin >> order[i];

		for (int j = 0; j < 4; ++j) {
			int num;
			cin >> num;

			like[order[i]][num] = 1;
		}
	}
}

void makeSeat(int now) {
	
	priority_queue<Info> pq; // �ڸ� �켱����

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {
			
			// �̹� Ȯ���� ���
			if (confirm[r][c] != 0)
				continue;

			Info tmp = { r, c, 0, 0 }; // ���� ��Ȳ

			// ������ �� Ȯ��
			for (int d = 0; d < 4; ++d) {
				int ny = r + dy[d];
				int nx = c + dx[d];

				// ���� ��
				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
					continue;

				// ���ڸ�
				if (confirm[ny][nx] == 0) {
					tmp.nEmpty++;
				}

				// �����ϴ� ��� �ִ� ���
				if (like[now][confirm[ny][nx]] == 1) {
					tmp.nLike++;
				}
			}

			pq.push(tmp);
		}
	}

	// �ڸ� Ȯ��
	Info result = pq.top();
	confirm[result.y][result.x] = now;
}

void calcScore() {

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c) {

			int cnt = 0; // ���� �����ϴ� ��� ��
			for (int d = 0; d < 4; ++d) {
				int ny = r + dy[d];
				int nx = c + dx[d];

				// ���� ��
				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
					continue;

				// �����ϴ� ��� �ִ� ���
				if (like[confirm[r][c]][confirm[ny][nx]] == 1) {
					cnt++;
				}
			}

			answer += score[cnt];
		}
	}
}


void solution() {

	for (int i = 0; i < n * n; ++i) {

		makeSeat(order[i]);
	}

	calcScore();

	cout << answer;
}

int main() {
	
	input();

	solution();
}