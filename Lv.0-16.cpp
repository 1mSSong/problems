#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;

    for (int i = 0; i < queries.size(); i++) {
        string tmp = "";
        tmp += answer.substr(0, queries[i][0]);
        for (int j = queries[i][1]; j >= queries[i][0]; j--) {
            tmp += answer[j];
        }
        tmp += answer.substr(queries[i][1] + 1);

        answer = tmp;
    }
    return answer;
}