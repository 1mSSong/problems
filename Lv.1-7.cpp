#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> fail(N + 1);
    vector<int> cnt(N + 2, 0);
    for (int i = 0; i < stages.size(); i++) {
        cnt[stages[i]]++;
    }
    int per = stages.size();
    for (int i = 1; i < N + 1; i++) {
        fail[i].second = i;
        if (per == 0) {
            fail[i].first = 0;
        }
        else {
            fail[i].first = cnt[i] / (double)per;
        }
        per -= cnt[i];
    }
    sort(fail.begin() + 1, fail.end(), compare);
    for (int i = 1; i < fail.size(); i++) {
        answer.push_back(fail[i].second);
    }
    return answer;
}