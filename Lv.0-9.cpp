#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    for (int i = 0; i < quiz.size(); i++) {
        vector<string> tmp;
        stringstream ss(quiz[i]);
        string s1;
        while (ss >> s1) {
            tmp.push_back(s1);
        }

        int tmpAns;
        if (tmp[1] == "+") {
            tmpAns = stoi(tmp[0]) + stoi(tmp[3]);
        }
        else {
            tmpAns = stoi(tmp[0]) - stoi(tmp[3]);
        }

        if (tmpAns == stoi(tmp[5])) {
            answer.push_back("O");
        }
        else {
            answer.push_back("X");
        }
    }
    return answer;
}