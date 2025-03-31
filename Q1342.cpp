#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
int answer;
int len; // 문자열 길이
int cnt[26]; // 알파벳 개수

vector<char> tmp_str;

void input() {

	cin >> s;

	len = s.length();
	tmp_str.resize(len);

	for (int i = 0; i < len; ++i) {
		cnt[s[i] - 'a']++;
	}

}

void isLucky() {
	
	for (int i = 1; i < len; ++i) {
		if (tmp_str[i - 1] == tmp_str[i])
			return;
	}

	answer++;
	return;
}

void func(int now) {

	if (now == len) {
		isLucky();
	
		return;
	}

	for (int i = 0; i < 26; ++i) {
		
		if (cnt[i] == 0)
			continue;

		tmp_str[now] = 'a' + i;
		cnt[i]--;

		func(now + 1);

		tmp_str[now] = 0;
		cnt[i]++;
	}
}

int main() {

	input();

	func(0);

	cout << answer;
}