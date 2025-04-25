#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct EnInfo {
	int y, x;
	int is_alive; // 1: 살아있음, 0: 성 침입, -1: 공격
	
	bool operator < (EnInfo& right) const {
		return x < right.x;
	}
};

int n, m, d;
int answer;

vector<vector<int>> map; // 초기 적 위치
int loc[3]; // 궁수 위치
vector<EnInfo> enemy; // 적 위치
vector < EnInfo> tmp_enemy; // 각 턴마다 사용

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
	
	int attack[3] = { -1, -1, -1 }; // 공격할 적 번호
	int dist[3] = { 2100000000, 2100000000, 2100000000 }; // 공격할 적과의 거리

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < tmp_enemy.size(); ++j) {
			EnInfo now = tmp_enemy[j];

			//cout << "!!!! now!!!\n";
			//cout << now.y << " " << now.x << "\n";

			// 게임에서 제외된 경우
			if (now.is_alive != 1) {
				continue;
			}

			int now_dist = distance({ now.y, now.x }, { n, loc[i] });
			// cout << now_dist << "\n";

			// D 밖
			if (now_dist > d)
				continue;
			
			if (now_dist < dist[i]) {
				dist[i] = now_dist;
				attack[i] = j;
			}
		}
	}

	// 공격
	for (int i = 0; i < 3; ++i) {
		if (attack[i] == -1)
			continue;

		tmp_enemy[attack[i]].is_alive = -1;
	}

	// cout << "=====공격=====\n";
	// cout << attack[0] << " " << attack[1] << " " << attack[2] << "\n";
}

void MoveEnemy() {
	for (int i = 0; i < tmp_enemy.size(); ++i) {
		if (tmp_enemy[i].is_alive != 1)
			continue;

		// 이동
		tmp_enemy[i].y++;
		
		if (tmp_enemy[i].y == n) {
			tmp_enemy[i].is_alive = 0;

		}
	}
}

// 다 없어질 때 까지
void ChangeTurn() {

	tmp_enemy = enemy;

	while (1) {

		// 모든 적 X
		int cnt = 0;
		for (int i = 0; i < tmp_enemy.size(); ++i) {
			if (tmp_enemy[i].is_alive == 1) {
				cnt++;
				break;
			}
		}

		if (cnt == 0)
			break;

		// 공격할 적 선택 
		ChooseEnemy();

		// 남은 적들 이동
		MoveEnemy();

	}
	
	int tmp_answer = 0;

	// 제거한 적 확인
	for (int i = 0; i < tmp_enemy.size(); ++i) {
		if (tmp_enemy[i].is_alive == -1)
			tmp_answer++;
	}
	
	// cout << "tmp answer : " << tmp_answer << "\n";
	answer = max(tmp_answer, answer);
}

void DFS(int level, int idx) {

	if (level == 3) {

		// cout << "====궁수위치====\n";
		// cout << loc[0] << " " << loc[1] << " " << loc[2] << "\n";
		// 적 선택
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
