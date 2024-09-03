#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int t;
string s; // 원본 문자열
int times; // 교환 횟수

string answer;
int ans;
bool flag; // 정답인지

void init() {
    ans = -1;
    flag = false;
}

void input() {
    cin >> s >> times;
    // 1. 88832 처럼 최댓값이 나오는 경우 (기회 2번)
    // 2. 82883 처럼 최댓값이 나오지 않는 경우 (기회 1번)

    answer = s;

    sort(answer.begin(), answer.end(), greater<>());
}

bool isTwo(string s) {
    int DAT[10];

    for (int i = 0; i < 10; ++i) {
        DAT[i] = 0;
    }
    for (int i = 0; i < s.length(); ++i) {
        DAT[s[i] - '0']++;
    }

    for (int i = 0; i < 10; ++i) {
        if (DAT[i] > 1)
            return true;
    }

    return false;
}

void dfs(string s, int cnt) {
    // 3. 최댓값을 찾은 경우
    // 남은 횟수에 따라 다르게 처리
    if (s == answer) {
        // 남은 횟수
        int left = times - cnt;

        // 짝수
        if (left % 2 == 0) {
            ans = stoi(s);
            flag = true;
            return;
        }

        // 홀수
        else {
            // 중복되는 수 있음
            if (isTwo(s)) {
                ans = stoi(s);
                flag = true;
                return;
            }
            else {
                swap(s[s.length() - 1], s[s.length() - 2]);
                ans = stoi(s);
                flag = true;
                return;
            }
        }
    }

    // 2. 기저조건
    // 최댓값을 만드는 경우
    // 최댓값을 만들지 못하는 경우
    // 횟수가 꽉찬 경우
    if (cnt == times) {
        ans = max(ans, stoi(s));

        return;
    }

    // 1. 기본 재귀
    // 하나의 카드 선택, swap하는 모든 방법
    for (int i = 0; i < s.size() - 1; ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            // left <= right : 바꾸는게 정답에 가까움
            if (s[i] >= s[j])
                continue;

            swap(s[i], s[j]);

            dfs(s, cnt + 1);

            if (flag)
                return;
            swap(s[i], s[j]);


        }
    }
}

void solution() {
    dfs(s, 0);
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