#include <iostream>
#include <vector>

using namespace std;

int dat[101]; // dat[i] : i를 약수로 가지는 개수
int n;
vector<int> r; // 난로의 반지름


void Input() {

    cin >> n;
    r.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
}


void Divisor(int num) {

    for (int i = 2; i <= num; ++i) {
        if (num % i == 0) {
            dat[i]++;
        }
    }

    return;
}

void Solution() {

    for (int i = 0; i < n; ++i) {
        Divisor(r[i]);
    }

    int answer = 0;

    for (int i = 0; i < 100; ++i) {
        answer = max(answer, dat[i]);
    }

    cout << answer;
}

int main(int argc, char** argv)
{
    Input();

    Solution();

    return 0;
}