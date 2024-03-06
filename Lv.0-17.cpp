#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;

    int pos = myString.find(pat, 0);
    if (pos == string::npos) {
        return 0;
    }

    int lastPos = string::npos;

    while (pos != string::npos) {
        lastPos = pos;
        pos = myString.find(pat, pos + 1);
        answer++;
    }
    return answer;
}