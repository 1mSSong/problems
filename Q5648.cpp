#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

struct Node {
    int x, y;
    int dir;
    int energy;
    int isAlive;
};

int t;
int n;

int cnt;
int ans;

int MAP[4002][4002];
vector<Node> v;

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void init() {
    memset(MAP, 0, sizeof(MAP));

    ans = 0;
    cnt = 0;

    v.resize(0);
}

void input() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y, dir, energy;
        cin >> x >> y >> dir >> energy;

        // 매핑
        x = (x + 1000) * 2;
        y = (y + 1000) * 2;

        cnt++; // 살아있는 원자 개수
        v.push_back({ x, y, dir, energy, 1 });
        
        MAP[x][y] = 1; // 원자의 존재 여부 체크
    }
}

void solution() {
    // 1. 일단 움직이기
    while (cnt > 0) {
        for (int i = 0; i < v.size(); ++i) {
         
            Node now = v[i];

            if (now.isAlive == 0)
                continue;

            int nx = now.x + dx[now.dir];
            int ny = now.y + dy[now.dir];

            if (ny >= 4000 || nx >= 4000 || ny < 0 || nx < 0) {
                v[i].isAlive = 0;
                MAP[now.x][now.y] = 0;
                cnt--;
                continue;
            }

            // 이동
            MAP[nx][ny] += 1;

            // 기존 좌표는 지워주기
            MAP[now.x][now.y] = 0;

            // 위치 갱신
            v[i].x = nx;
            v[i].y = ny;
        }

        // 2. 충돌 여부에 따라 방출되는 에너지 연산
        // 2개 이상의 원자가 만났을 때, 방출되는 에너지의 총합?

        for (int i = 0; i < v.size(); ++i) {
            Node now = v[i]; // 갱신된 정보 확인

            if (now.isAlive == 0)
                continue;

            if (MAP[now.x][now.y] >= 2) {
                ans += now.energy;
                v[i].isAlive = 0;
                cnt--;
            }
        }

        for (int i = 0; i < v.size(); ++i) {
            Node now = v[i];

            if (MAP[now.x][now.y] >= 2) {
                MAP[now.x][now.y] = 0;
            }
        }

    }
    
}

int main() {
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        init();

        input();

        solution();

        cout << "#" << tc << " " << ans << "\n";
    }
}