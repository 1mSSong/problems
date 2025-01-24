#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt[2]; // 0: O의 개수, 1: X의 개수

int flag[2]; // O / X가 빙고를 만든 개수

int answer = 1;
vector<string> board;

void chk_bingo() {

    for (int i = 0; i < 3; ++i) {

        if (board[i] == "OOO") {
            flag[0]++;
        }
        else if (board[i] == "XXX") {
            flag[1]++;
        }
        // 세로 
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'O') {
                flag[0]++;
            }
            else if (board[0][i] == 'X') {
                flag[1]++;
            }

        }

    }

    // 대각선
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'O') {
            flag[0]++;
        }
        else if (board[0][0] == 'X') {
            flag[1]++;
        }

    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {

        if (board[0][2] == 'O') {
            flag[0]++;
        }
        else if (board[0][2] == 'X') {
            flag[1]++;
        }


    }

}

void win() {

    if (flag[0] != 0 && flag[1] != 0) {
        answer = 0;
        return;
    }

    // O가 이기면
    if (flag[0] != 0) {

        // 개수 O = X + 1
        if (cnt[0] != cnt[1] + 1) {
            answer = 0;
            return;
        }

    }

    // 1이 이기면
    if (flag[1] != 0) {

        // 개수 O = X
        if (cnt[0] != cnt[1]) {
            answer = 0;
            return;
        }
    }


}

int solution(vector<string> boards) {
    board = boards;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {

            if (board[i][j] == 'O')
                cnt[0]++;
            else if (board[i][j] == 'X') {
                cnt[1]++;
            }
        }
    }

    // 개수로 확인
    if (cnt[0] < cnt[1]) {
        answer = 0;
        return answer;
    }

    if (cnt[0] - cnt[1] > 1) {
        answer = 0;
        return answer;
    }

    chk_bingo();

    win();

    return answer;
}