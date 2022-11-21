#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct people {
	string name;
	int dd, mm, year;
};

bool compare(people a, people b) {
	if (a.year == b.year) {
		if (a.mm == b.mm) return a.dd < b.dd;
		else return a.mm < b.mm;
	}
	return a.year < b.year;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<people> res(n);
	for (int i = 0; i < n; i++) {
		cin >> res[i].name >> res[i].dd >> res[i].mm >> res[i].year;
	}
	sort(res.begin(), res.end(), compare);
	cout << res[n - 1].name << "\n" << res[0].name;
}