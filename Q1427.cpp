#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct people {
	int age;
	string name;
	int order;
};

bool compare(people a, people b);

int main() {
	int N;
	cin >> N;
	vector<people> P(N);

	for (int i = 0; i < N; i++) {
		cout << "AA";
		cin >> P[i].age;
		cin >> P[i].name;
		P[i].order = i;
	}

	sort(P.begin(), P.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << P[i].age << " " << P[i].name;
	}

}

bool compare(people a, people b) {
	if (a.age == b.age) {
		return a.order < b.order;
	}
	return a.age < b.age;
}