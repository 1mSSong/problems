#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;

    for (int i = 0; i < progresses.size(); i++) {
        days.push(ceil((100.0 - progresses[i]) / speeds[i]));
    }


    int tmp = 1;
    int chk = days.front();
    days.pop();

    while (!days.empty()) {
        if (chk >= days.front()) {
            tmp++;
            days.pop();
        }
        else {
            answer.push_back(tmp);
            tmp = 0;
            chk = days.front();
        }
    }
    answer.push_back(tmp);


    return answer;
}