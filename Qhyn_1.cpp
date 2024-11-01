#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> p;

int n, m;

vector<vector<char>> map;
vector<p> alpha[26];
vector<int> answer;

void input() {
	cin >> n >> m;

	map.assign(n, vector<char>(m, 0));
	answer.resize(m + 1);

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;

		// n * m map 만들기
		for (int j = 0; j < 2 * m - 1; ++j) {
			if (str[j] == '.')
				continue;

			map[i][j / 2] = str[j];

			// 알파벳의 경우 따로 저장
			if (str[j] >= 'a' && str[j] <= 'z') {
				alpha[str[j] - 'a'].push_back({ i, j / 2 });
			}
		}
	}
}

void solution(int now) {
	int y = 0, x = now;

	while (1) {
		if (y >= n)
			break;

		if (map[y][x] == '|') {
			y++;
		}
		else if (map[y][x] >= 'a' && map[y][x] <= 'z') {
			int c = map[y][x] - 'a';

			if (alpha[c][0].first == y && alpha[c][0].second == x) {
				y = alpha[c][1].first;
				x = alpha[c][1].second;
				y++;
			}

			else if (alpha[c][1].first == y && alpha[c][1].second == x) {
				y = alpha[c][0].first;
				x = alpha[c][0].second;
				y++;
			}
		}

	}

	answer[x + 1] = now + 1;
}

int main() {
	input();

	for (int i = 0; i < m; ++i) {
		solution(i);
	}


	for (int i = 1; i <= m; ++i) {
		cout << answer[i] << " ";
	}
}