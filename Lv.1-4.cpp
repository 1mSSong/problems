#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> prime;
    prime.push_back(2);

    for (int i = 3; i <= n; i++) {
        bool chk = true;
        for (int j = 0; j <= sqrt(prime.size()); j++) {
            if (i % prime[j] == 0) {
                chk = false;
                break;
            }
        }
        if (chk) {
            prime.push_back(i);
        }
    }
    answer = prime.size();
    return answer;
}