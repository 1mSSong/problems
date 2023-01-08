#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string solution(string polynomial) {
    string answer = "";
    vector<string> seq;
    stringstream ss(polynomial);
    string s1;
    while (ss >> s1) {
        seq.push_back(s1);
    }

    int constN = 0;
    int poly = 0;

    for (int i = 0; i < seq.size(); i++) {
        if (seq[i] == "+") continue;
        if (seq[i][seq[i].length() - 1] == 'x') {
            if (seq[i].length() == 1) {
                poly += 1;
                continue;
            }
            seq[i][seq[i].length() - 1] == ' ';
            poly += stoi(seq[i]);
        }
        else {
            constN += stoi(seq[i]);
        }
    }

    if (poly == 0 && constN != 0) {
        answer = to_string(constN);
    }
    else if (poly != 0 && constN == 0) {
        if (poly == 1) {
            answer = "x";
        }
        else {
            answer = to_string(poly) + "x";
        }

    }
    else {
        if (poly == 1) {
            answer = "x + " + to_string(constN);
        }
        else {
            answer = to_string(poly) + "x + " + to_string(constN);
        }
    }

    return answer;
}