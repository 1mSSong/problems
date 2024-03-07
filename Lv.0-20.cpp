#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    int row = arr.size(), col = arr[0].size();

    if (row < col) {
        for (int i = 0; i < row; i++) {
            answer.push_back(arr[i]);
        }

        for (int i = 0; i < col - row; i++) {
            vector<int> tmp(col, 0);
            answer.push_back(tmp);
        }
    }
    else if (row > col) {

        for (int i = 0; i < row; i++) {
            vector<int> tmp;

            for (int j = 0; j < col; j++)
                tmp.push_back(arr[i][j]);
            for (int j = 0; j < row - col; j++)
                tmp.push_back(0);
            answer.push_back(tmp);
        }
    }
    else {
        for (int i = 0; i < row; i++) {
            answer.push_back(arr[i]);
        }
    }
    return answer;
}