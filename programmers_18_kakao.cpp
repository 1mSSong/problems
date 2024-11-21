#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string, int> chk_map;
vector<string> now_cache;

string change(string str) {

    string new_str = "";

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            new_str += str[i];
        }
        else {
            char c = str[i] - 'A' + 'a';
            new_str += c;
        }
    }

    return new_str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize == 0) {
        answer = cities.size() * 5;
        return answer;
    }

    for (int i = 0; i < cities.size(); ++i) {

        cities[i] = change(cities[i]);

        // 캐시에 존재
        if (chk_map[cities[i]]) {
            chk_map[cities[i]] = i + 1;
            answer += 1;
        }

        // 캐시에 존재 X
        else {
            answer += 5;

            // 남은 자리 존재
            if (now_cache.size() < cacheSize) {
                now_cache.push_back(cities[i]);
                chk_map[cities[i]] = i + 1;
            }

            // 남은 자리 존재 X
            else {

                int index = 0;

                for (int j = 1; j < now_cache.size(); ++j) {

                    if (chk_map[now_cache[j]] < chk_map[now_cache[index]]) {
                        index = j;
                    }
                }

                chk_map[now_cache[index]] = 0;
                now_cache[index] = cities[i];

                chk_map[cities[i]] = i + 1;
            }

        }
    }

    return answer;
}