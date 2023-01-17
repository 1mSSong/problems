#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int tY, tM, tD;
    tY = stoi(today.substr(0, 4));
    tM = stoi(today.substr(5, 2));
    tD = stoi(today.substr(8, 2));

    map<string, int> term;
    for (int i = 0; i < terms.size(); i++) {
        term[terms[i].substr(0, 1)] = stoi(terms[i].substr(2));
    }

    for (int i = 0; i < privacies.size(); i++) {
        int tempY, tempM, tempD;
        tempY = stoi(privacies[i].substr(0, 4));
        tempM = stoi(privacies[i].substr(5, 2));
        tempD = stoi(privacies[i].substr(8, 2));

        tempM += term[privacies[i].substr(11)];

        tempD--;
        if (tempD == 0) {
            tempM--;
            tempD = 28;
        }
        if (tempM == 0) {
            tempM = 12;
            tempY--;
        }

        tempY += (tempM / 12);
        tempM = tempM % 12;
        if (tempM == 0) {
            tempM = 12;
            tempY--;
        };
        if (tempY < tY) {
            answer.push_back(i + 1);
            continue;
        }
        else if (tempY > tY) continue;

        if (tempM < tM) {
            answer.push_back(i + 1);
            continue;
        }
        else if (tempM > tM) continue;

        if (tempD < tD) {
            answer.push_back(i + 1);
            continue;
        }
        else continue;


    }
    return answer;
}