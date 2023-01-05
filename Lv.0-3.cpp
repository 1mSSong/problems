#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int answer = 2;
    bool chk = false;

    for (int i = 0; i < str1.length() - str2.length() + 1; i++) {
        chk = false;
        if (str1[i] == str2[0]) {
            chk = true;
            for (int j = i; j < i + str2.length(); j++) {
                if (str1[j] != str2[j-i]) {
                    chk = false;
                    break;
                }
 
            }
            if (chk) {
                answer = 1;
                break;
            }
        }

    }
    cout << answer;
}