#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";

    int i = 0;
    int j = 0;
    while (i < s.length()) {
        if (s[i] == ' ') {
            answer += s[i];
            i++;
            j = 0;
            continue;
        }
        if (j % 2 == 0) {
            answer += toupper(s[i]);
            i++;
            j++;
        }
        else {
            answer += tolower(s[i]);
            i++;
            j++;
        }
    }
    return answer;
}