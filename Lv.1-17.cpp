#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int cnt[26] = { 0, };

    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            if (cnt[keymap[i][j] - 'A'] == 0)
                cnt[keymap[i][j] - 'A'] = j + 1;
            else {
                if (cnt[keymap[i][j] - 'A'] > j + 1)
                    cnt[keymap[i][j] - 'A'] = j + 1;
            }
        }
    }

    for (int i = 0; i < targets.size(); i++) {
        int tmp = 0;

        for (int j = 0; j < targets[i].size(); j++) {
            if (cnt[targets[i][j] - 'A'] == 0) {
                tmp = -1;
                goto label1;
            }

            tmp += cnt[targets[i][j] - 'A'];
        }
    label1:
        answer.push_back(tmp);
    }
    return answer;
}