#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> prime;

void isPrime(int n) {
    bool chk;
    for (int i = 2; i <= n; i++) {
        chk = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                chk = false;
                break;
            }
        }
        if (chk) {
            prime.push_back(i);
        }

    }
}
vector<int> solution(int n) {
    vector<int> answer;
    isPrime(n);

    int index = 0;
    while (n != 1) {
        if (n % prime[index] == 0) {
            n = n / prime[index];
            answer.push_back(prime[index]);
        }
        else {
            index++;
        }
    }
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> sol = solution(n);

    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
}