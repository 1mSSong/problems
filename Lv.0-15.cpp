#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(pair<int, int> n1, pair<int, int> n2) {
    if (n1.second == n2.second)
        return n1.first < n2.first;
    return n1.second > n2.second;
}

int solution(int a, int b, int c, int d) {
    int answer = 0;
    vector<pair<int, int>> cnt(7);

    for (int i = 0; i < cnt.size(); i++) {
        cnt[i] = { i, 0 };
    }
    cnt[a].second++;
    cnt[b].second++;
    cnt[c].second++;
    cnt[d].second++;

    sort(cnt.begin(), cnt.end(), compare);

    if (cnt[0].second == 4) {
        answer = 1111 * cnt[0].first;
    }
    else if (cnt[0].second == 3) {
        answer = pow((10 * cnt[0].first + cnt[1].first), 2);
    }
    else if (cnt[0].second == 2) {
        if (cnt[1].second == 2) {
            answer = (cnt[0].first + cnt[1].first) * abs(cnt[0].first - cnt[1].first);
        }
        else {
            answer = cnt[1].first * cnt[2].first;
        }
    }
    else {
        answer = cnt[0].first;
    }
    return answer;
}