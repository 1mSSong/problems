#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printAvg(vector<int> num);
void printMid(vector<int> num);
void printbin(vector<int> num);
void printRange(vector<int> num);
bool compare(pair<int, int> a, pair<int, int> b);

int main() {
	int N;
	cin >> N;

	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	printAvg(num);
	printMid(num);
	printbin(num);
	printRange(num);
}

void printAvg(vector<int> num) {
	int sum = 0;
	for (unsigned int i = 0; i < num.size(); i++) {
		sum += num[i];
	}
	double result;
	if (sum < 0) {
		sum = -sum;
		result = (double)sum / num.size();
		result = int(-result-0.5);
	}
	else {
		result = (double)sum / num.size();
		result = int(result + 0.5);
	}
	cout << result << endl;;
	
	
}

void printMid(vector<int> num) {
	cout << num[num.size() / 2] << endl;
}

void printbin(vector<int> num) {
	if (num.size() == 1) {
		cout << num[0] << endl;
		return;
	}

	vector<pair<int, int>> a;
	a.push_back(make_pair(num[0], 1));
	int idx = 0;
	for (int i = 1; i < num.size(); i++) {
	
		if (num[i] == num[i - 1]) {
			a[idx].second += 1;
		}
		else {
			idx++;
			a.push_back(make_pair(num[i], 1));
		}
	}
	sort(a.begin(), a.end(), compare);
	

	if (a[0].second != a[1].second) {
		cout << a[0].first << endl;
	}
	else {
		cout << a[1].first << endl;
	}

}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return b.second < a.second;
}

void printRange(vector<int> num) {
	cout << num[num.size() - 1] - num[0] << endl;
}
