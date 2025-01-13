#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, m;
pii LR[2];

// 각 행의 환경 파괴자 수
vector<int> cnt_person;

void input() {
    cin >> n >> m;

    cnt_person.resize(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            int map;
            cin >> map;

            if (map == 1) {
                cnt_person[i]++;
            }
        }
    }

    for (int i = 0;i < 2; ++i) {
        cin >> LR[i].first >> LR[i].second;

        // 0부터 만들어주기 위함
        LR[i].first--;
        LR[i].second--;
    }
}

void solution() {

    for (int i = 0; i < 2; ++i) {

        for (int j = LR[i].first; j <= LR[i].second; ++j) {

            cnt_person[j]--;
        }
    }

    int answer = 0;

    for (int i = 0; i < n; ++i) {

        if (cnt_person[i] < 0)
            continue;

        answer += cnt_person[i];
    }

    cout << answer;
}

int main(int argc, char** argv)
{
    input();

    solution();

    return 0;
}