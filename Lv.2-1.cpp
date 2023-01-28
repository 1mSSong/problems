#include <string>
#include <vector>
#include <iostream>
using namespace std;

char firstChar(char a) {
    if ((a - '0') >= 0 && (a - '0') < 10) {
        return a;
    }
    else {
        return toupper(a);
    }
}

char notFirst(char a) {
    if ((a - '0') >= 0 && (a - '0') < 10) {
        return a;
    }
    else {
        return tolower(a);
    }
}

string solution(string s) {
    string answer = "";
    answer += firstChar(s[0]);

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += " ";
            continue;
        }

        if (s[i - 1] == ' ') {
            answer += firstChar(s[i]);
        }
        else {
            answer += notFirst(s[i]);
        }
    }
    return answer;
}