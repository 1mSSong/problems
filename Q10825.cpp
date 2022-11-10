#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct student {
	string name;
	int kor, eng, math;
};

bool compare(student a, student b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			return a.math > b.math;
		}
		return a.eng < b.eng;
	} 
	return a.kor > b.kor;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<student> st(n);

	for (int i = 0; i < n; i++) {
		cin >> st[i].name;
		cin >> st[i].kor >> st[i].eng >> st[i].math;
	}

	sort(st.begin(), st.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << st[i].name << "\n";
	}
}