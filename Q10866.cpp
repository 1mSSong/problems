#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

void push_front(int X, vector<int>& q);
void push_back(int X, vector<int>& q);
void pop_front(vector<int>& q);
void pop_back(vector<int>& q);
void size(vector<int>& q);
void empty(vector<int>& q);
void front(vector<int>& q);
void back(vector<int>& q);

int main() {
	int N;
	cin >> N;

	vector<int> Q;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		if (s == "size") {
			size(Q);
		}
		else if (s == "empty") {
			empty(Q);
		}
		else if (s == "front") {
			front(Q);
		}
		else if (s == "back") {
			back(Q);
		}
		else if (s == "push_front") {
			int X;
			cin >> X;
			push_front(X, Q);
		}
		else if (s == "push_back") {
			int X;
			cin >> X;
			push_back(X, Q);
		}
		else if (s == "pop_front") {
			pop_front(Q);
		}
		else {
			pop_back(Q);
		}
	}

		
		
}

void push_front(int X, vector<int>& q) {
	q.insert(q.begin(), X);
}

void push_back(int X, vector<int>& q) {
	q.push_back(X);
}
void pop_front(vector<int>& q) {
	if (q.empty()) {
		cout << "-1\n";
	}
	else {
		cout << q[0] << "\n";
		q.erase(q.begin());
	}
}

void pop_back(vector<int>& q) {
	if (q.empty()) {
		cout << "-1\n";
	}
	else {
		cout << q[q.size() - 1] << "\n";
		q.pop_back();
	}
}

void size(vector<int>& q) {
	cout << q.size() << "\n";
}

void empty(vector<int>& q) {
	if (q.empty()) cout << "1\n";
	else cout << "0\n";
}

void front(vector<int>& q) {
	if (q.empty()) {
		cout << "-1\n";
	}
	else cout << q[0] << "\n";
}

void back(vector<int>& q) {
	if (q.empty()) {
		cout << "-1\n";
	}
	else cout << q[q.size() - 1] << "\n";
}