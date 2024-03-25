#include <string>
#include <iostream>
using namespace std;

int SDT(char c, int n) {
    if (c == 'S')
        return n;

    else if (c == 'D')
        return n * n;

    else if (c == 'T')
        return n * n * n;
}

int solution(string dartResult) {
    int answer = 0;

    int prev = 0, now = 0;
    for (int i = 0; i < dartResult.size(); i++) {

        if (((dartResult[i] - '0') >= 0) && ((dartResult[i] - '0') < 10)) {
            prev = now;
            if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
                i++;
                now = SDT(dartResult[i + 1], 10);
            }
            else {
                now = SDT(dartResult[i + 1], (dartResult[i] - '0'));
            }
        }


        if (dartResult[i + 2] == '*') {
            now = now * 2;
            answer += prev;
            i++;
        }
        else if (dartResult[i + 2] == '#') {
            now = -now;
            i++;
        }
        else {

        }
        answer += now;
        i++;
    }
    return answer;
}