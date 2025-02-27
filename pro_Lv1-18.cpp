#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string, int> id; // key: id, value: ���� ��ȣ
unordered_map<string, unordered_set<string>> count; // key: id, value: �Ű��� ��� ���

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());

    // ���� ��ȣ �ο�
    for (int i = 0; i < id_list.size(); ++i) {
        id[id_list[i]] = i;
    }

    for (int i = 0; i < report.size(); ++i) {

        int index = 0;
        for (int j = 0; j < report[i].length(); ++j) {
            if (report[i][j] == ' ') {
                index = j;
                break;
            }
        }

        string str1 = report[i].substr(0, index); // �Ű���
        string str2 = report[i].substr(index + 1); // �Ű� ���� ���

        count[str2].insert(str1);

    }

    // �Ű� ���� kȸ
    for (auto item : count) {

        if (count[item.first].size() >= k) {

            for (auto it : count[item.first]) {
                answer[id[it]]++;
            }
        }
    }
    return answer;
}