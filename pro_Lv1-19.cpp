#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    int n = schedules.size();

    // 희망 출근 + 10
    for (int i = 0; i < n; ++i) {
        int h = schedules[i] / 100;
        int m = schedules[i] % 100;

        int total = h * 60 + m + 10;

        h = total / 60;
        m = total % 60;

        schedules[i] = h * 100 + m;
    }

    // 주말 출근 -1
    if (startday == 7) {

        for (int i = 0; i < n; ++i) {
            timelogs[i][6] = -1;
            timelogs[i][0] = -1;
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            timelogs[i][6 - startday] = -1;
            timelogs[i][7 - startday] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {

        // 정상출근 count
        int cnt = 0;

        for (int j = 0; j < 7; ++j) {

            if (timelogs[i][j] == -1)
                continue;

            if (schedules[i] >= timelogs[i][j])
                cnt++;
        }

        if (cnt >= 5)
            answer++;
    }
    return answer;
}