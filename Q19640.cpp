#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Info {
	int D;
	int H;
	int lineNum; // 현재 대기중인 라인 번호
	int num; // 도착 순서

	bool operator < (Info right) const {

		if (D == right.D) {

			if (H == right.H) {
				return lineNum > right.lineNum;
			}

			return H < right.H;
		}
		return D < right.D;
	}
};

int n, m, k;
int answer;

vector<vector<Info>> line; // 각 line에 서 있는 사람 정보
vector<int> index; // 현재 선두인 사람의 번호
priority_queue<Info> pq; // 선두인 사람의 모임

void input() {

	cin >> n >> m >> k;

	line.resize(m);
	index.resize(m);

	for (int i = 0; i < n; ++i) {

		int d, h;
		cin >> d >> h;

		int tmp_line = i % m;

		line[tmp_line].push_back({ d, h, tmp_line, i + 1 });
	}

}

void solution() {

	// 초기 선두 다 pq에 넣기
	for (int i = 0; i < m; ++i) {
		
		if (!line[i].empty()) {
			pq.push(line[i][0]);
			index[i]++;
		}
	}
	while (1) {
		
		// 각 라인 선두 중 가장 먼저 이용할 사람
		Info now = pq.top();
		pq.pop();


		if (now.num == k + 1)
			break;

		answer++;

		// now.lineNum의 모든 사람 이용
		if (index[now.lineNum] >= line[now.lineNum].size()) {
			continue;
		}

		pq.push(line[now.lineNum][index[now.lineNum]]);
		index[now.lineNum]++;
	}

	cout << answer;
	
}

int main() {

	input();

	solution();
}