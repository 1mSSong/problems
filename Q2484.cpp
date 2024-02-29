#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> dice;
vector<int> price;

bool compare(int a, int b) {
	return a > b;
}

void calculate() {

	for (int i = 0; i < n; i++) {
		// 4개 모두 같은 경우
		if (dice[i][0] == dice[i][3])
			price[i] = 50000 + dice[i][0] * 5000;

		// 3개만 같은 경우
		else if (dice[i][0] == dice[i][2])
			price[i] = 10000 + dice[i][0] * 1000;

		// 2개씩 두 쌍
		else if (dice[i][0] == dice[i][1] && dice[i][2] == dice[i][3])
			price[i] = 2000 + dice[i][0] * 500 + dice[i][2] * 500;

		// 모두 다른 경우
		else if(dice[i][0] != dice[i][1] && dice[i][1] != dice[i][2] && dice[i][2] != dice[i][3])
			price[i] = dice[i][0] * 100;

		// 2개만 같은 경우
		else {
			if (dice[i][0] == dice[i][1])
				price[i] = 1000 + dice[i][0] * 100;
			else if (dice[i][1] == dice[i][2])
				price[i] = 1000 + dice[i][1] * 100;
			else if (dice[i][2] == dice[i][3])
				price[i] = 1000 + dice[i][2] * 100;
		}
	}

}
int main() {

	cin >> n;

	dice.assign(n, vector<int>(4));
	price.assign(n, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++)
			cin >> dice[i][j];
	
		sort(dice[i].begin(), dice[i].end(), compare);
	}

	calculate();

	sort(price.begin(), price.end(), compare);
	cout << price[0];

}