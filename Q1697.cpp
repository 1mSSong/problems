#include <iostream>
#include <queue>
using namespace std;

int n, k;
int visited[100001];

struct Info {
	int location;
	int t;
};

int main() {
	cin >> n >> k;

	queue<Info> q;
	q.push({ n, 0 });

	while (!q.empty()) {
		Info now = q.front();
		q.pop();

		visited[now.location] = 1;

		if (now.location == k) {
			cout << now.t;
			break;
		}
		
		if (now.location - 1 >= 0 && visited[now.location - 1] != 1) {
			q.push({ now.location - 1, now.t + 1 });
		}
		
		if (now.location + 1 <= 100000 && visited[now.location + 1] != 1) {
			q.push({ now.location + 1, now.t + 1 });
		}

		if (now.location * 2 <= 100000 && visited[now.location * 2] != 1) {
			q.push({ now.location * 2, now.t + 1 });
		}
	}
}