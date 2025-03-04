#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int answer;

vector<vector<int>> map;

pii now;
int d;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void input() {
	cin >> n >> m;

	map.resize(n, vector<int>(m, 0));

	cin >> now.first >> now.second >> d;

	for (int i = 0;i < n;++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
}

void solution() {

	while (1) {

		// ���� ĭ û�� �ʿ�
		if (map[now.first][now.second] == 0) {
			
			map[now.first][now.second] = -1;
			
			answer++;
			continue;
		}

		int flag = 0; // �̵� ���� ����
		
		// �ݽð���� ȸ��
		for (int i = 1; i <= 4; ++i) {

			int now_i = (4 - i) % 4;
			int ny = now.first + dy[(now_i + d) % 4];
			int nx = now.second + dx[(now_i + d) % 4];

			// ���� ��
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// ��
			if (map[ny][nx] == 1)
				continue;
			
			// û�� ����
			if (map[ny][nx] == 0) {
				
				now.first = ny;
				now.second = nx;
				d += now_i;
				d %= 4;

				flag = 1;

				break;
			}
		}

		// û�� �Ұ��� ����
		if (flag == 0) {
			// ���� ���� �Ǵ�
			int ny = now.first + dy[(2 + d) % 4];
			int nx = now.second + dx[(2 + d) % 4];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (map[ny][nx] == 1) {
				return;
			}

			// ����
			now.first = ny;
			now.second = nx;
		}
	}
}

int main() {
	
	input();

	solution();

	cout << answer;
}