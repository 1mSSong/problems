#include <string>
#include <vector>
#include <iostream>
using namespace std;

// r, d, l, u
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    answer.assign(n, vector<int>(n, -1));

    int tmp = n;
    int num = 1, d = 0;
    int i = 0, j = 0;

    answer[0][0] = num;
    for (int k = 1; k < n; k++) {
        num++;
        i = i + dx[d];
        j = j + dy[d];
        answer[i][j] = num;
    }
    tmp--;
    d = (d + 1) % 4;

    while (num < n * n) {
        for (int k = 0; k < 2; k++) {
            for (int l = 0; l < tmp; l++) {
                i = i + dx[d];
                j = j + dy[d];
                num++;
                answer[i][j] = num;
            }
            d = (d + 1) % 4;
        }
        tmp--;
    }


    return answer;
}