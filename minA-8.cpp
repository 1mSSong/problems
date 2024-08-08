#include <iostream>
#include <vector>
using namespace std;

int t;
int n;
long long ans;

vector<int> arr;
vector<int> visited; // 풍선이 터졌는지 확인 (터졌으면 1 아니면 0)
vector<int> dat; // 중복 확인


void init() {
	
	arr.clear();
	visited.clear();
	dat.clear();

	ans = 0;
}

void input() {
	cin >> n;

	arr.resize(n);
	visited.resize(n);
	dat.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

// 중복이 불가능한, 순서가 상관 있는
void dfs(int now, long long sum) {
	if (now >= n) {

		ans = max(sum, ans);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (dat[i] == 1)
			continue;

		dat[i] = 1;
		visited[i] = 1;

		// 얻을 수 있는 점수
		long long tmp = 0;

		// if문 들어갈지 말지 결정
		int flag = 0;
		// 주위에 아무것도 없을 때
		if (now == n - 1) {
			flag = 1;
			tmp = arr[i];
		}
			
		
		if (!flag) {
			int left = i - 1, right = i + 1;

			// 터지지 않은 왼쪽 풍선 찾기
			while (1) {
				if (left < 0)
					break;

				if (visited[left] != 1) {
					break;
				}
				left--;
			}

			// 터지지 않은 오른쪽 풍선 찾기
			while (1) {
				if (right >= n)
					break;

				if (visited[right] != 1)
					break;

				right++;
			}

			// 양쪽 다 있을 때
			if (left >= 0 && left < n && right >= 0 && right < n) {
				tmp = arr[left] * arr[right];
			}
			// 양쪽 다 없을 때
			else if ((left < 0 || left >= n) && (right < 0 || right >= n)) {
				tmp = arr[i];
			}
			// 한쪽만 있을 때
			else {
				if (left < 0)
					tmp = arr[right];
				else if (right >= n) {
					tmp = arr[left];
				}
			}
			
		}
		
		dfs(now + 1, sum + tmp);

		visited[i] = 0;
		dat[i] = 0;

	}
}


int main() {
	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		dfs(0, 0);
		 
		cout << "#" << tc << " " << ans << "\n";
	}
}