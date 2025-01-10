#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0, 0 };

    // 중복 확인용 map
    unordered_map<string, int> chk; // value = 1 -> 이미 존재

    // 현재 몇번째 턴인지
    int turn = 1;

    // 탈락자 번호
    int num = 0;


    for (int i = 0; i < words.size(); ++i) {

        // 이미 존재
        if (chk[words[i]] == 1) {
            answer = { num + 1, turn };
            break;
        }

        // 끝말있기 규칙 위반
        if (i > 0 && words[i - 1][words[i - 1].size() - 1]
            != words[i][0]) {

            answer = { num + 1, turn };
            break;
        }

        // 새로운 차례
        if ((num + 1) % n == 0) {
            turn++;
        }

        num++;
        num %= n;
        chk[words[i]] = 1;
    }

    return answer;
}