#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info {
	int index;
	int value;
	int color; // 0: red, 1:blue
	int next_index[2]; // 없으면 -1
};

int answer;
int loc[4];
int dice[10];
Info graph[33];

void input() {
	for (int i = 0; i < 10; ++i) {
		cin >> dice[i];
	}
}

void init() {

	graph[0] = { 0, 0, 0, {1, -1} };
	for (int i = 1; i <= 19; ++i) {
		graph[i] = { i, 2 * i, 0, {i + 1, -1} };

		if (i % 5 == 0) {
			graph[i].color = 1;
		}
	}
	graph[5].next_index[1] = 20;
	graph[10].next_index[1] = 24;
	graph[15].next_index[1] = 26;
	graph[19].next_index[0] = 31;

	for (int i = 0; i <= 2; ++i) {
		graph[i + 20] = { i + 20, 13 + i * 3, 0, {i + 21, -1 } };
	}

	graph[23] = { 23, 25, 0, {29, -1} };
	graph[24] = { 24, 22, 0, {25, -1} };
	graph[25] = { 25, 24, 0, {23, -1} };


	for (int i = 26; i <= 28; ++i) {
		graph[i] = { i, 54 - i, 0, {i + 1, -1} };
	}
	graph[28].next_index[0] = 23;

	for (int i = 29; i <= 31; ++i) {
		graph[i] = { i, 30 + (i - 29) * 5, 0, {i + 1, -1} };
	}
	graph[32] = { 32, 0, 0, {32, 32} };
}


void dfs(int level, int score) {
	if (level == 10) {

		answer = max(answer, score);
		return;
	}


	for (int i = 0; i < 4; ++i) {
		if (loc[i] >= 32)
			continue;

		int now_loc = loc[i];
		int next_loc = loc[i];
		int tmp = now_loc;

		if (graph[now_loc].color == 1) {
			tmp = graph[now_loc].next_index[1];
		}
		else {
			tmp = graph[now_loc].next_index[0];
		}

		for (int j = 1; j < dice[level]; ++j) {
			if (tmp == 32)
				break;
			tmp = graph[tmp].next_index[0];
		}

		next_loc = tmp;

		int flag = 0;
		// 중복 확인
		for (int j = 0; j < 4; ++j) {

			if (i == j)
				continue;

			if (next_loc == 32)
				continue;

			if (loc[j] == 32)
				continue;

			if (next_loc == loc[j]) {
				flag = 1;
				break;
			}
		}

		if (flag) {
			continue;
		}

		loc[i] = next_loc;

		dfs(level + 1, score + graph[next_loc].value);

		loc[i] = now_loc;

	}
}

int main() {

	input();

	init();

	dfs(0, 0);

	cout << answer;
}