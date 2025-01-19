#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map <int, int> um_front, um_back;
vector<int> dp_front, dp_back; // 앞에서부터, 뒤에서부터

int solution(vector<int> topping) {
    int answer = 0;

    int len = topping.size();

    dp_front.resize(len);
    dp_back.resize(len);

    dp_front[0] = 1;
    um_front[topping[0]] = 1;

    dp_back[len - 1] = 1;
    um_back[topping[len - 1]] = 1;

    for (int i = 1; i < len - 1; ++i) {

        // 이미 존재
        if (um_front[topping[i]] == 1) {
            dp_front[i] = dp_front[i - 1];
        }
        else {
            dp_front[i] = dp_front[i - 1] + 1;
            um_front[topping[i]] = 1;
        }


        if (um_back[topping[len - 1 - i]] == 1) {
            dp_back[len - 1 - i] = dp_back[len - i];
        }
        else {
            dp_back[len - 1 - i] = dp_back[len - i] + 1;
            um_back[topping[len - 1 - i]] = 1;
        }
    }

    for (int i = 0; i < len - 1; ++i) {
        if (dp_front[i] == dp_back[i + 1])
            answer++;
    }
    return answer;
}