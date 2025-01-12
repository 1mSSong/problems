#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> height;
vector<int> dp; // 밟을 수 있는 최대 돌의 개수

int answer = 1;

void input() {

    cin >> n;

    height.resize(n);
    dp.resize(n, 1);

    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }
}

void lis() {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {

            if (height[i] > height[j]) {

                dp[i] = max(dp[i], dp[j] + 1);
                answer = max(dp[i], answer);
            }
        }
    }
}

void solution() {

    lis();

    cout << answer;
}

int main(int argc, char** argv)
{

    input();

    solution();

    return 0;
}