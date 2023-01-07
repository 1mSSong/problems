#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int solution(string s) {
    stringstream ss(s);
    string s1;
    vector<string> seq;
    int i = 0;
    while (ss >> s1) {
        seq.push_back(s1);
    }
    int answer = stoi(seq[0]);
    for (int i = 1; i < seq.size(); i++) {
        if (seq[i] == "Z") {
            answer -= stoi(seq[i - 1]);
        }
        else {
            answer += stoi(seq[i]);
        }
    }

    return answer;
}

int main() {
    string s;
    getline(cin, s);
    cout << solution(s);
}