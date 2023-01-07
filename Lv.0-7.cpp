#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool chk3(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '3') return true;
    }
    return false;
}

bool supply(int n) {
    if (n % 3 == 0) return true;
    else return false;
}

int solution(int n) {
    int answer = 0;
    vector<int> dp(101);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= 100; i++) {
        dp[i] = dp[i - 1] + 1;
        while (chk3(to_string(dp[i])) == true || supply(dp[i]) == true) {
            dp[i]++;
        }
    }
    answer = dp[n];

    return answer;
}

int main() {
    int n;
    cin >> n;
    cout << solution(n);
}