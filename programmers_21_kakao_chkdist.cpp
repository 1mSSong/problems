#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

vector<pii> person;

int dist(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void init() {
    person.clear();
}

int func(vector<string> str) {
    int arr[5][5];

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (str[i][j] == 'P') {
                person.push_back({ i, j });
                arr[i][j] = 1;
            }
            else if (str[i][j] == 'O') {
                arr[i][j] = 0;
            }
            else if (str[i][j] == 'X') {
                arr[i][j] = -1;
            }
        }
    }

    int p = person.size();

    for (int i = 0; i < p; ++i) {
        for (int j = i + 1; j < p; ++j) {
            int d = dist(person[i], person[j]);

            if (d >= 3)
                continue;

            if (d <= 1)
                return 0;

            // 맨해튼 거리 2
            // 같은 행
            if (person[i].first == person[j].first) {
                int cnt = 0;

                int a = min(person[i].second, person[j].second);
                int b = max(person[i].second, person[j].second);

                for (int k = a; k <= b; ++k) {
                    if (arr[person[i].first][k] == -1)
                        cnt++;
                }

                if (cnt == 1)
                    continue;
                else
                    return 0;
            }

            // 같은 열 
            if (person[i].second == person[j].second) {

                int cnt = 0;

                int a = min(person[i].first, person[j].first);
                int b = max(person[i].first, person[j].first);

                for (int k = a; k <= b; ++k) {
                    if (arr[k][person[i].second] == -1)
                        cnt++;
                }

                if (cnt == 1)
                    continue;
                else
                    return 0;

            }

            // 대각선 위치
            int x[2], y[2];
            int cnt = 0;
            y[0] = min(person[i].first, person[j].first);
            y[1] = max(person[i].first, person[j].first);

            x[0] = min(person[i].second, person[j].second);
            x[1] = max(person[i].second, person[j].second);

            for (int k = y[0]; k <= y[1]; ++k) {
                for (int a = x[0]; a <= x[1]; ++a) {
                    if (arr[k][a] == -1)
                        cnt++;
                }
            }

            if (cnt >= 2)
                continue;

            else
                return 0;
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < 5; ++i) {

        init();
        answer.push_back(func(places[i]));
    }
    return answer;
}