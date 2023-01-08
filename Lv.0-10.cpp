#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int minx = lines[0][0];
    int maxx = lines[0][1];

    for (int i = 1; i < lines.size(); i++) {
        if (minx > lines[i][0]) minx = lines[i][0];
        if (maxx < lines[i][1]) maxx = lines[i][1];
    }

    map<int, int> chk;
    for (int i = minx; i < maxx; i++) {
        chk[i] = 0;
    }

    for (int i = 0; i < lines.size(); i++) {
        for (int j = lines[i][0]; j < lines[i][1]; j++) {
            chk[j] = chk[j] + 1;
        }
    }
    for (auto i = chk.begin(); i != chk.end(); i++) {
        if (i->second > 1) answer++;
    }
    return answer;
}