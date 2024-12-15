#include <iostream>
#include <vector>
using namespace std;

int n, k;

int answer;

vector<int> bitstr; // 단어에 포함되면 1, 아니면 0

long long allset; // 모든 경우

void input() {
	
	cin >> n >> k;
	
	for (int i = 0; i < n; ++i) {

		string str;
		cin >> str;

		int now = 0;

		for (int j = 0; j < str.length(); ++j) {

			int c = str[j] - 'a';
			now |= (1 << c);
		}

		bitstr.push_back(now);
	}

}

void dfs(int level, int next) {

	if (level == k - 5) {
		
		int tmpanswer = 0;

		for (int i = 0; i < n; ++i) {

			if ((allset & bitstr[i]) == bitstr[i]) {

				tmpanswer++;
			}
		}

		answer = max(answer, tmpanswer);

		return;
	}

	for (int i = next; i < 26; ++i) {
		
		// 이미 배운 알파벳
		if (((allset >> i) & 1) == 1)
			continue;

		allset |= (1 << i);

		dfs(level + 1, i + 1);

		allset &= ~(1 << i);
	}
}

void solution() {

	string ess = "antic";

	for (int j = 0; j < 5; ++j) {

		int c = ess[j] - 'a';
		allset |= (1 << c);
	}
	
	if (k < 5) {

		answer = 0;
		return;
	}


	dfs(0, 0);

	
}

int main() {

	input();


	solution();

	cout << answer;
}