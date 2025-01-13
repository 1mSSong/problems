#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

vector<vector<int>> map;
int visited[210][210]; // 방문 처리

void fillMap(vector<vector<int>> rectangle) {

    map.assign(210, vector<int>(210, -1));

    // 가장자리는 1
    // 내부는 0
    for (int i = 0; i < rectangle.size(); ++i) {

        for (int j = 0; j < 4; ++j) {
            rectangle[i][j] *= 2;
        }

        for (int x = rectangle[i][0]; x <= rectangle[i][2]; ++x) {
            for (int y = rectangle[i][1]; y <= rectangle[i][3]; ++y) {

                // 바깥선
                if (x == rectangle[i][0] || x == rectangle[i][2] ||
                    y == rectangle[i][1] || y == rectangle[i][3]) {

                    // 다른 사각형의 내부가 아닐 때만 1
                    if (map[y][x] != 0) {
                        map[y][x] = 1;
                    }
                }
                // 내부
                else {
                    map[y][x] = 0;
                }
            }
        }
    }
}

int bfs(int y, int x, int itemY, int itemX) {
    queue<pii> q;

    q.push({ y, x });
    visited[y][x] = 1;

    while (!q.empty()) {
        pii now = q.front();
        q.pop();

        if (now.first == itemY && now.second == itemX)
            return visited[now.first][now.second];

        for (int i = 0; i < 4; ++i) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];

            // 범위 밖
            if (ny < 0 || nx < 0 || ny >= 210 || nx >= 210)
                continue;

            // 이미 방문
            if (visited[ny][nx] != 0)
                continue;

            // 1로만 이동
            if (map[ny][nx] != 1)
                continue;

            q.push({ ny ,nx });
            visited[ny][nx] = visited[now.first][now.second] + 1;

        }
    }

}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {


    fillMap(rectangle);

    int answer = bfs(characterY * 2, characterX * 2, itemY * 2, itemX * 2);

    // 처음 시작 위치 제외
    answer--;

    // 2배수 원상복구
    answer /= 2;

    return answer;
}