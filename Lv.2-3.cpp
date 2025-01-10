#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Info {
    int sizes;
    int cnt;

    bool operator < (Info right) const {
        return cnt > right.cnt;
    }
};

// key : size, value : cnt
unordered_map <int, int> all_item;
vector<Info> size_tang;

void sortItem() {
    for (auto item : all_item) {
        size_tang.push_back({ item.first, item.second });
    }

    sort(size_tang.begin(), size_tang.end());

}

int cntType(int k) {

    int answer = 0;
    int now = 0; // 박스에 있는 귤 개수

    for (int i = 0; i < size_tang.size(); ++i) {

        answer++;
        now += size_tang[i].cnt;

        if (now >= k) {
            return answer;
        }
    }

    return answer;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    for (int i = 0; i < tangerine.size(); ++i) {
        all_item[tangerine[i]]++;
    }

    sortItem();

    answer = cntType(k);
    return answer;
}