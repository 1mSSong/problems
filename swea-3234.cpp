#include <iostream>
#include <vector>
using namespace std;

int t;

int n; // 개수
int arr[10]; // 무게
int expo[10];
int fact[10];

int visited[10]; // index: 무게 추의 순번, value: 사용 여부
vector<int> path;

vector<int> LeftChoo;
vector<int> RightChoo;

int ans;
int cnt;
int sum;

void init() {
	ans = 0;
	cnt = 0;
	sum = 0;

	path.clear();
	LeftChoo.clear();
	RightChoo.clear();

	for (int i = 0; i < 10; ++i) {
		visited[i] = 0;
		arr[i] = 0;
	}
}

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];

		sum += arr[i];
	}
}

void dfs1(int now) {
	if (now >= n) {
		for (int i = 0; i < path.size(); ++i) {
			cout << path[i] << " ";
		}
		cout << "\n";
		cnt++;

		return;
	}

	for (int i = 0; i < n; ++i) {
		if (visited[i])
			continue;

		path.push_back(arr[i]);
		visited[i] = 1;

		dfs1(now + 1);

		path.pop_back();
		visited[i] = 0;
	}
}

void dfs2(int now, int left, int right) {
	// 양팔 저울 왼쪽, 오른쪽 나눠서 올리는 모든 경우의 수 확인
	// 양팔 저울 고장 X

	if (now >= n) {
		cout << "result(" << cnt << ")\n";


		for (int i = 0; i < LeftChoo.size(); ++i) {
			cout << LeftChoo[i] << " ";
		}
		cout << " | ";


		for (int i = 0; i < RightChoo.size(); ++i) {
			cout << RightChoo[i] << " ";
		}
		cout << "\n";
		cnt++;
		return;
	}

	for (int i = 0; i < n; ++i) {
		
		if (visited[i])
			continue;

		// 무조건 왼쪽부터 놓아야 함
		LeftChoo.push_back(arr[i]);
		visited[i] = 1;


		dfs2(now + 1, left + arr[i], right);

		LeftChoo.pop_back();
		visited[i] = 0;
		
		// 백트래킹 1
		// 추를 올렸을 때 오른쪽이 더 크면 그 이후 보지 않음 -> continue
		if (left < right + arr[i])
			continue;

		// 오른쪽 놓기
		RightChoo.push_back(arr[i]);
		visited[i] = 1;

		dfs2(now + 1, left, right + arr[i]);

		RightChoo.pop_back();
		visited[i] = 0;
	}
}

void dfs3(int now, int left, int right) {
	// 양팔 저울 왼쪽, 오른쪽 나눠서 올리는 모든 경우의 수 확인
	// 양팔 저울 고장 X

	if (now >= n) {
		cnt++;
		return;
	}

	// 무게 총 합의 절반 이상을 넘었다면 -> continue
	// 남아 있는 무게추들로 만들 수 있는 조합들을 카운팅

	for (int i = 0; i < n; ++i) {

		if (visited[i])
			continue;

		if (left > sum / 2) {
			cnt += (expo[n - now] * fact[n - now]);
			return;
			
		}
		// 무조건 왼쪽부터 놓아야 함

		visited[i] = 1;

		dfs3(now + 1, left + arr[i], right);

		visited[i] = 0;

		// 백트래킹 1
		// 추를 올렸을 때 오른쪽이 더 크면 그 이후 보지 않음 -> continue
		if (left < right + arr[i])
			continue;

		// 오른쪽 놓기
		visited[i] = 1;

		dfs3(now + 1, left, right + arr[i]);

		visited[i] = 0;
	}
}
void solution() {
	dfs3(0, 0, 0);
	ans = cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	expo[0] = 1;
	for (int i = 1; i < 10; ++i) {
		fact[i] = fact[i - 1] * i;
		expo[i] = expo[i - 1] * 2;

	}

	cin >> t;

	for (int tc = 1; tc <= t; ++tc) {
		init();

		input();

		solution();

		cout << "#" << tc << " " << ans << "\n";
	}
}