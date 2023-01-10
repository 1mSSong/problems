#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> tmp;

    for (int i = 0;; i++)
    {
        tmp.push_back(n % 3);
        n /= 3;
        if (n == 0) break;
    }
    for (int i = 0; i < tmp.size(); i++) {
        answer += tmp[i] * pow(3, tmp.size() - i - 1);
    }
    return answer;
}