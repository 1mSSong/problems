#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
int cntDiv(int n) {
    int tmp = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) tmp++;
    }

    tmp *= 2;
    if (n == ((int)sqrt(n) * (int)sqrt(n)))
        tmp--;
    return tmp;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; i++) {
        int cnt = cntDiv(i);
        if (cnt > limit) cnt = power;
        answer += cnt;
    }
    return answer;
}