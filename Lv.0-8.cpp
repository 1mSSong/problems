#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int solution(string my_string) {
    int answer = 0;

    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] >= 'A' && my_string[i] <= 'Z') {
            my_string[i] = ' ';
        }
        if (my_string[i] >= 'a' && my_string[i] <= 'z') {
            my_string[i] = ' ';
        }
    }

    stringstream ss(my_string);
    string tmp;
    while (ss >> tmp) {
        if (tmp != " ") {
            answer += stoi(tmp);
        }
    }

    return answer;
}
 
int main() {
    string s;
    cin >> s;
    cout << solution(s);
}