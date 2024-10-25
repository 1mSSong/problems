#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<int> arr;
vector<char> answer;

int n;

int index;

void input() {
	cin >> n;
	
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

bool solution() {

	for (int i = 1; i <= n; ++i) {
		answer.push_back('+');
		s.push(i);

		while (1) {
			if (index >= n)
				break;

			if (s.empty())
				break;

			if (s.top() != arr[index])
				break;

			s.pop();
			answer.push_back('-');
			index++;
		}
	}

	return s.empty();
}

int main() {
	input();


	if (solution()) {
		for (int i = 0; i < answer.size(); ++i) {
			cout << answer[i] << "\n";
		}
	}
	else {
		cout << "NO";
	}
	 
}