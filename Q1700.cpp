#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int res; // 뺀 개수

vector<int> ele;
vector<queue<int>> order;

vector<int> multi;

void input() {
	cin >> n >> k;

	ele.resize(k + 1);
	order.resize(k + 1);

	for (int i = 0; i < k; ++i) {
		int tmp;
		cin >> tmp;

		ele[i] = tmp;

		order[tmp].push(i);
	}

	multi.resize(n);
	

}

void solution() {
	
	for (int i = 0; i < k; ++i) {
		// 현재 확인할 전기용품 번호
		int now = ele[i];
		int flag = 0;


		// 멀티탭에 꽂혀있는지
		for (int j = 0; j < n; ++j) {
			if (multi[j] == now) {
				flag = 1;
				break;
			}
		}

		// 꽂혀있으면 다음 단계
		if (flag) {
			if (!order[now].empty())
				order[now].pop();
			continue;
		}
			
		// 꽂을 자리가 있을 때
		for (int j = 0; j < n; ++j) {
			if (multi[j] == 0) {
				multi[j] = now;
				flag = 1;
				break;
			}
		}

		if (flag) {
			if (!order[now].empty())
				order[now].pop();
			continue;
		}
			
		// 꽂혀있지 않을 때
		// 꽂혀 있는 전기용품 중 앞으로 가장 최근에 나오지 않는 전기용품 빼기
		
		int lateIndex = 0; // 꽂혀있는 멀티탭 위치

		for (int j = 0; j < n; ++j) {

			// 다음에 더 이상 나오지 않음
			if (order[multi[j]].empty()) {
				lateIndex = j;
				break;
			}

			if (order[multi[j]].front() > order[multi[lateIndex]].front()) {
				lateIndex = j;
			}
		}
		

		res++;
		multi[lateIndex] = now;

		if (order[now].empty())
			continue;

		order[now].pop();
	}
}

int main() {
	input();

	solution();

	cout << res;
}