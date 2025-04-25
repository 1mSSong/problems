#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct EnInfo {
	int y, x;
	int is_alive; // 1: �������, 0: �� ħ��, -1: ����
	
	bool operator < (EnInfo& right) const {
		return x < right.x;
	}
};

int n, m, d;
int answer;

vector<vector<int>> map; // �ʱ� �� ��ġ
int loc[3]; // �ü� ��ġ
vector<EnInfo> enemy; // �� ��ġ
vector < EnInfo> tmp_enemy; // �� �ϸ��� ���

void Input() {
	cin >> n >> m >> d;
	map.resize(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				enemy.push_back({ i, j, 1 });
			}
		}
	}

	sort(enemy.begin(), enemy.end());
}

int distance(pair<int, int> a1, pair<int, int> b1) {
	return abs(a1.first - b1.first) + abs(a1.second - b1.second);
}

void ChooseEnemy() {
	
	int attack[3] = { -1, -1, -1 }; // ������ �� ��ȣ
	int dist[3] = { 2100000000, 2100000000, 2100000000 }; // ������ ������ �Ÿ�

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < tmp_enemy.size(); ++j) {
			EnInfo now = tmp_enemy[j];

			//cout << "!!!! now!!!\n";
			//cout << now.y << " " << now.x << "\n";

			// ���ӿ��� ���ܵ� ���
			if (now.is_alive != 1) {
				continue;
			}

			int now_dist = distance({ now.y, now.x }, { n, loc[i] });
			// cout << now_dist << "\n";

			// D ��
			if (now_dist > d)
				continue;
			
			if (now_dist < dist[i]) {
				dist[i] = now_dist;
				attack[i] = j;
			}
		}
	}

	// ����
	for (int i = 0; i < 3; ++i) {
		if (attack[i] == -1)
			continue;

		tmp_enemy[attack[i]].is_alive = -1;
	}

	// cout << "=====����=====\n";
	// cout << attack[0] << " " << attack[1] << " " << attack[2] << "\n";
}

void MoveEnemy() {
	for (int i = 0; i < tmp_enemy.size(); ++i) {
		if (tmp_enemy[i].is_alive != 1)
			continue;

		// �̵�
		tmp_enemy[i].y++;
		
		if (tmp_enemy[i].y == n) {
			tmp_enemy[i].is_alive = 0;

		}
	}
}

// �� ������ �� ����
void ChangeTurn() {

	tmp_enemy = enemy;

	while (1) {

		// ��� �� X
		int cnt = 0;
		for (int i = 0; i < tmp_enemy.size(); ++i) {
			if (tmp_enemy[i].is_alive == 1) {
				cnt++;
				break;
			}
		}

		if (cnt == 0)
			break;

		// ������ �� ���� 
		ChooseEnemy();

		// ���� ���� �̵�
		MoveEnemy();

	}
	
	int tmp_answer = 0;

	// ������ �� Ȯ��
	for (int i = 0; i < tmp_enemy.size(); ++i) {
		if (tmp_enemy[i].is_alive == -1)
			tmp_answer++;
	}
	
	// cout << "tmp answer : " << tmp_answer << "\n";
	answer = max(tmp_answer, answer);
}

void DFS(int level, int idx) {

	if (level == 3) {

		// cout << "====�ü���ġ====\n";
		// cout << loc[0] << " " << loc[1] << " " << loc[2] << "\n";
		// �� ����
		ChangeTurn();

		return;
	}

	for (int i = idx; i < m; ++i) {
		loc[level] = i;

		DFS(level + 1, i + 1);
		
		loc[level] = 0;
	}
}

void Solution() {
	DFS(0, 0);

	cout << answer;
}

int main() {

	Input();

	Solution();
}
