#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int win[46] = { 0, };
    for (int i = 0; i < win_nums.size(); i++) {
        win[win_nums[i]]++;
    }

    int same = 0;
    int unknown = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0)
            unknown++;
        if (win[lottos[i]] != 0)
            same++;
    }

    if (same + unknown <= 1)
        answer.push_back(6);
    else
        answer.push_back(7 - same - unknown);

    if (same == 0)
        same = 1;
    answer.push_back(7 - same);

    return answer;
}