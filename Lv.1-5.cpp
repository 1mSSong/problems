#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        stack<int> tmp1;
        stack<int> tmp2;

        for (int j = 0; j < n; j++)
        {
            if (arr1[i] % 2 == 1) tmp1.push(1);
            else tmp1.push(0);
            arr1[i] /= 2;

            if (arr2[i] % 2 == 1) tmp2.push(1);
            else tmp2.push(0);
            arr2[i] /= 2;
        }
        string tmp = "";
        for (int j = 0; j < n; j++) {
            if (tmp1.top() || tmp2.top()) tmp += "#";
            else tmp += " ";
            tmp1.pop();
            tmp2.pop();
        }
        answer.push_back(tmp);


    }
    return answer;
}