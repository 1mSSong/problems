#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

bool compare(int a, int b) {
    if (abs(a) == abs(b)) {
        return a < b;
    }
    return abs(a) < abs(b);
}

int solution(vector<int> array, int n) {
    int answer = 0;
    for (int i = 0; i < array.size(); i++) {
        array[i] = array[i] - n;
    }
    sort(array.begin(), array.end(), compare);
    answer = array[0] + n;
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> array;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        array.push_back(a);
    }

    int num;
    cin >> num;

    cout << solution(array, num);
}