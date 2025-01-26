#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Info {
    string name;
    int start_time;
    int end_time;
    int res_time;

    bool operator < (Info right) const {

        return start_time < right.start_time;
    }
};

vector<Info> work; // 전체 과제
stack<Info> remainder; // 덜 끝난 과제
vector<string> answer;

void input(vector<vector<string>> plans) {

    int len = plans.size();

    for (int i = 0; i < len; ++i) {
        int h, m, play_time;

        h = stoi(plans[i][1].substr(0, 2));
        m = stoi(plans[i][1].substr(3));
        play_time = stoi(plans[i][2]);

        Info now;
        now.name = plans[i][0];
        now.start_time = h * 60 + m;
        now.end_time = now.start_time + play_time;
        now.res_time = play_time;

        work.push_back(now);
    }
}

void doWork() {
    sort(work.begin(), work.end());
    int len = work.size();

    for (int i = 0; i < len - 1; ++i) {

        Info now = work[i];
        Info next = work[i + 1];

        if (now.end_time > next.start_time) {
            now.res_time -= (next.start_time - now.start_time);
            remainder.push(now);

        }
        else {
            answer.push_back(now.name);

            int now_time = next.start_time - now.end_time;

            // 남은 시간만큼 밀린 일 하기
            while (now_time != 0) {

                if (remainder.empty())
                    break;

                Info stack_now = remainder.top();
                remainder.pop();

                // 하나의 일 다 처리 가능
                if (now_time >= stack_now.res_time) {
                    answer.push_back(stack_now.name);

                    now_time -= stack_now.res_time;
                }
                // 처리 불가능
                else {
                    stack_now.res_time -= now_time;
                    remainder.push(stack_now);

                    now_time = 0;
                }
            }
        }
    }

    answer.push_back(work[len - 1].name);

    // 남은 일 처리 -> 순서대로
    while (!remainder.empty()) {
        answer.push_back(remainder.top().name);
        remainder.pop();
    }
}

vector<string> solution(vector<vector<string>> plans) {

    input(plans);

    doWork();

    return answer;
}