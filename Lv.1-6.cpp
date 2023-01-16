#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x = s[0];
    int cntx = 1;
    int notx = 0;
    for (int i = 1; i < s.length(); i++) {
        if (x == s[i]) cntx++;
        else notx++;

        if (cntx == notx) {
            answer++;
            cntx = 0;
            notx = 0;
            if (i != s.length() - 1) x = s[i + 1];
        }
    }
    if ((cntx + notx) != 0) answer++;
    return answer;
}