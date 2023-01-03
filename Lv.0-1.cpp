#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

using namespace std;

int solution(vector<int> array) {
    int answer = -1;
    sort(array.begin(), array.end());
    vector<pair<int, int>> cnt;
    cnt.push_back(make_pair(array[0], 1));

    int idx = 0;
    for (int i = 1; i < array.size(); i++) {
        if (array[i] == array[i - 1]) {
            cnt[idx].second++;
        }
        else {
            cnt.push_back(make_pair(array[i], 1));
            idx++;
        }
    }

    pair<int, int> max = make_pair(cnt[0].first, cnt[0].second);
    for (int i = 1; i < cnt.size(); i++) {
        if (max.second < cnt[i].second) {
            max.second = cnt[i].second;
            max.first = cnt[i].first;
        }
    }

    int chk = 0;
    for (int i = 0; i < cnt.size(); i++) {
        if (max.second == cnt[i].second) chk++;
    }
    if (chk == 1) {
        answer = max.first;
    }
    else {
        answer = -1;
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> array;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        array.push_back(tmp);
    }

    cout<< solution(array);
}