#include<iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

string message, key;
int msg_len, key_len;

char map[5][5]; // 5*5 표
pii coord[26]; // 알파벳위치

int DAT[26];

vector<string> word;

string answer;

void input() {
    cin >> message >> key;

    msg_len = message.length();
    key_len = key.length();

    DAT[9] = 1;
    coord[9] = { -1, -1 };
}

void fillMap() {
    int y = 0, x = 0;

    for (int i = 0; i < key_len; ++i) {

        if (DAT[key[i] - 'A'])
            continue;

        map[y][x] = key[i];
        coord[key[i] - 'A'] = { y, x };
        DAT[key[i] - 'A'] = 1;

        x++;

        if (x == 5) {
            y++;
            x = 0;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (DAT[i])
            continue;

        char c = (char)('A' + i);

        map[y][x] = c;
        coord[i] = { y, x };
        DAT[i] = 1;
        x++;

        if (x == 5) {
            y++;
            x = 0;
        }
    }
}

void divideStr() {
    int index = 0;

    while (1) {
        if (index >= msg_len)
            break;

        if (index == msg_len - 1) {

            string tmp = "";
            tmp += message[index];
            tmp += "X";

            word.push_back(tmp);
            index += 2;
            break;
        }

        string c1 = "";
        c1 += message[index];

        string c2 = "";
        c2 += message[index + 1];


        if (c1 != c2) {
            word.push_back(c1 + c2);
            index += 2;
        }
        else {
            if (c1 != "X") {
                word.push_back(c1 + "X");
                index++;
            }
            else {
                word.push_back(c1 + "Q");
                index++;
            }
        }

    }
}

void solution() {
    int w_size = word.size();

    for (int i = 0; i < w_size; ++i) {
        pii c1 = coord[word[i][0] - 'A'];
        pii c2 = coord[word[i][1] - 'A'];

        // 행 동일
        if (c1.first == c2.first) {
            int y = c1.first;

            int x1 = (c1.second + 1) % 5;
            int x2 = (c2.second + 1) % 5;

            answer += map[y][x1];
            answer += map[y][x2];
        }

        else if (c1.first != c2.first && c1.second == c2.second) {
            int x = c1.second;

            int y1 = (c1.first + 1) % 5;
            int y2 = (c2.first + 1) % 5;

            answer += map[y1][x];
            answer += map[y2][x];
        }

        else if (c1.first != c2.first && c1.second != c2.second) {

            int y1 = c1.first;
            int y2 = c2.first;

            int x1 = c2.second;
            int x2 = c1.second;

            answer += map[y1][x1];
            answer += map[y2][x2];
        }
    }
}

int main(int argc, char** argv)
{
    input();

    fillMap();

    divideStr();

    solution();

    cout << answer;
    return 0;
}