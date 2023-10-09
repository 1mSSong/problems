#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Student {
public:
	string name;
	int score;

	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	bool operator < (Student& other) {
		return this->score < other.score;
	}
};

int main() {
	int n;
	cin >> n;

	vector<Student> students;

	for (int i = 0; i < n; i++) {
		string name;
		int score;
		cin >> name >> score;
		students.push_back(Student(name, score));
	}

	sort(students.begin(), students.end());

	for (int i = 0; i < n; i++) {
		cout << students[i].name << " ";
	}
	
}