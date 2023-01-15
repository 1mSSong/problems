#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while (n >= a) {
        if (n % a == 0) {
            answer = answer + b * (n / a);
            n = (n / a) * b;
        }
        else {
            answer = answer + b * ((n - n % a) / a);
            n = ((n - n % a) / a) * b + n % a;
        }
    }
    return answer;
}