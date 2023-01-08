#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<string> babbling;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        babbling.push_back(tmp);
    }
    int answer = 0;

    for (int i = 0; i < babbling.size(); i++) {
        int len = babbling[i].length();
        int idx = 0;
        int chk = true;

        while (len > 0 && chk == true) {
            if (len == 1) {
                chk = false;
                break;
            }
            int caseN;
            if (babbling[i].substr(idx, 2) == "ye") caseN = 0;
            else if (babbling[i].substr(idx, 2) == "ma") caseN = 1;
            else if (babbling[i].substr(idx, 2) == "ay") caseN = 2;
            else if (babbling[i].substr(idx, 2) == "wo") caseN = 3;
            else caseN = 4;
            switch (caseN) {
            case 0:
                idx += 2;
                len -= 2;
                break;

            case 1:
                idx += 2;
                len -= 2;
                break;

            case 2:
                if (babbling[i][idx + 2] == 'a') {
                    idx += 3;
                    len -= 3;
                }
                else {
                    chk = false;
                }
                break;

            case 3:
                if (babbling[i][idx + 2] == 'o') {
                    idx += 3;
                    len -= 3;
                }
                else {
                    chk = false;
                }
                break;

            default:
                chk = false;
            }
        }
        if (chk) answer++;
    }
    return answer;
}