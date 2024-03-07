#include <string>
#include <vector>

using namespace std;

string solution(string a, string b) {
    string answer = "";

    int lenA = a.length(), lenB = b.length();
    int len = max(lenA, lenB);

    vector<int> res(len + 1);

    string tmpA = "", tmpB = "";

    for (int i = lenA; i <= len; i++) {
        tmpA += "0";
    }
    tmpA += a;

    for (int i = lenB; i <= len; i++) {
        tmpB += "0";
    }
    tmpB += b;

    for (int i = len; i >= 0; i--) {
        res[i] += (tmpA[i] - '0') + (tmpB[i] - '0');
        if (res[i] >= 10) {
            res[i - 1]++;
            res[i] -= 10;
        }
    }

    if (res[0] != 0)
        answer += to_string(res[0]);

    for (int i = 1; i < res.size(); i++) {
        answer += to_string(res[i]);
    }

    return answer;
}