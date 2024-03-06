#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    answer.assign(arr.begin(), arr.end());

    int cnt = 0;

    for (int i = 0; i <= 10; i++) {
        if (pow(2, i) == arr.size())
            return answer;
        else {
            if ((pow(2, i) < arr.size()) && (pow(2, i + 1) > arr.size())) {
                cnt = pow(2, i + 1) - arr.size();
                break;
            }
        }
    }

    vector<int> tmp(cnt, 0);
    answer.insert(answer.end(), tmp.begin(), tmp.end());

    return answer;
}