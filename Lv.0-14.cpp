#include <string>
#include <vector>
using namespace std;

string solution(string myString, string pat) {
    string answer = "";

    int index = myString.find(pat);
    int pos = string::npos;

    while (index != string::npos) {
        pos = index;
        index = myString.find(pat, index + 1);
    }

    answer = myString.substr(0, pos + pat.size());
    return answer;
}