#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

struct Info {

	vector<string> under_folder; // 하위 폴더명
	unordered_set<string> type_file; // 파일 종류
	int cnt_file; // 파일 개수
};

unordered_map<string, Info> path;
unordered_map<string, int> visited;

int n, m;
int q;

pair< unordered_set<string>, int> answer;

void input() {

	cin >> n >> m;

	for (int i = 0; i < n + m; ++i) {
		
		string p, f;
		int c;

		cin >> p >> f >> c;


		// 폴더
		if (c == 1) {

			path[p].under_folder.push_back(f);
		}
		// 파일
		else {

			path[p].cnt_file++;
			path[p].type_file.insert(f);
		}

	}
	
}


void dfs(string now) {

	if (path[now].under_folder.empty()) {
		return;
	}

	visited[now] = 1;

	for (int i = 0; i < path[now].under_folder.size(); ++i) {

		string next = path[now].under_folder[i];

		// 이미 방문
		if (visited[next])
			continue;

		
		answer.first.insert(path[next].type_file.begin(), path[next].type_file.end());
		answer.second += path[next].cnt_file;


		dfs(next);
	}
}

void solution() {

	cin >> q;

	for (int i = 0; i < q; ++i) {

		string query;
		cin >> query;

		vector<string> folder_path; // 폴더 계층

		int a = 0, b = 0;

		while (1) {
			b = query.find("/", a);

			if (b == -1) {
				folder_path.push_back(query.substr(a));
				break;
			}

			folder_path.push_back(query.substr(a, b - a));

			a = b + 1;
		}

		int len = folder_path.size();
		Info now = path[folder_path[len - 1]];

		answer.first.clear();
		answer.second = 0;
		visited.clear();

		answer.first.insert(
			now.type_file.begin(), now.type_file.end()
		);
		answer.second = now.cnt_file;

		dfs(folder_path[len - 1]);


		cout << answer.first.size() << " " << answer.second << "\n";
		
	}

}

int main() {
	
	input();

	solution();

}