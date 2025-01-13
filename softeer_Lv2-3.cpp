#include <iostream>
#include <cmath>
using namespace std;

int dp[16];
int dot[16];

int n;

void input() {
    cin >> n;
}

void solution() {

    dp[0] = 4;
    dot[0] = 2;

    for (int i = 1; i <= n; ++i) {
        dot[i] = 2 * dot[i - 1] - 1;
        dp[i] = pow(dot[i], 2);

    }

    cout << dp[n];
}


int main(int argc, char** argv)
{

    input();

    solution();

    return 0;
}