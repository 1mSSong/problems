#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for (int i = 1; i < food.size(); i++) {
        if (food[i] % 2 != 0) {
            food[i]--;
        }
        for (int j = 0; j < food[i] / 2; j++) {
            answer += to_string(i);
        }
    }
    answer += "0";
    int len = answer.length() - 2;
    for (int i = len; i >= 0; i--) {
        answer += answer[i];
    }
    return answer;
}