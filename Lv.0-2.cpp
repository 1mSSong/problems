#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    int size = numbers.size();
    answer = max(numbers[0] * numbers[1], numbers[size - 1] * numbers[size - 2]);
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        numbers.push_back(tmp);
    }
    cout << solution(numbers);
}