#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> forX(10);
    vector<int> forY(10);
    vector<int> com(10);
    for (int i = 0; i < X.length(); i++) {
        forX[X[i] - '0']++;
    }
    for (int i = 0; i < Y.length(); i++) {
        forY[Y[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        com[i] = min(forX[i], forY[i]);
    }

    for (int i = 9; i >= 1; i--) {
        for (int j = 0; j < com[i]; j++) {
            answer += to_string(i);
        }
    }
    if (answer == "") {
        if (com[0] == 0) {
            answer = "-1";
        }
        else {
            answer = "0";
        }
    }
    else {
        for (int i = 0; i < com[0]; i++) {
            answer += "0";
        }
    }

    return answer;
}