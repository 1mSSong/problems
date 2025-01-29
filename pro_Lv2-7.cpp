#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<pair<string, string>> tmp_answer; // uid 상태
unordered_map<string, string> nickname; // key: uid, value: 닉네임

vector<string> answer;

void splitStr(string str) {

    int a = 0, b = 0;

    vector<string> word;

    while (1) {
        b = str.find(' ', a);

        if (b == -1) {
            word.push_back(str.substr(a));
            break;
        }

        word.push_back(str.substr(a, b - a));
        a = b + 1;
    }

    tmp_answer.push_back({ word[1], word[0] });

    if (word[0] == "Change" || word[0] == "Enter") {
        nickname[word[1]] = word[2];
    }
}

void makeAnswer() {
    int len = tmp_answer.size();

    for (int i = 0; i < len; ++i) {

        string now = nickname[tmp_answer[i].first] + "님이 ";

        if (tmp_answer[i].second == "Enter") {
            now += "들어왔습니다.";
        }
        else if (tmp_answer[i].second == "Leave") {
            now += "나갔습니다.";
        }
        else {
            continue;
        }

        answer.push_back(now);
    }
}

vector<string> solution(vector<string> record) {

    int len = record.size();

    for (int i = 0; i < len; ++i) {
        splitStr(record[i]);
    }

    makeAnswer();

    return answer;
}