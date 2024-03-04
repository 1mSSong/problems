#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";

    sort(indices.begin(), indices.end());

    int j = 0;
    for (int i = 0; i < my_string.size(); i++) {
        if (i == indices[j]) {
            j++;
        }
        else {
            answer += my_string[i];
        }
    }
    return answer;
}