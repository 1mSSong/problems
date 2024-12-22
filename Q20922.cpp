#include <iostream>
#include <vector>
using namespace std;

int n, k;
int answer;

vector<int> dat;
vector<int> arr;

void input() {
	
	cin >> n >> k;

	dat.resize(200001);
	arr.resize(n);
	
	for (int i = 0; i < n; ++i) {

		cin >> arr[i];
		
	}
}

void solution() {

	int sindex = 0, eindex = 0;
	
	while (1) {


		if (eindex >= n)
			break;
		
		dat[arr[eindex]]++;

		if (dat[arr[eindex]] > k) {
			
			while (1) {

				if (dat[arr[eindex]] == k)
					break;

				if (sindex == eindex)
					break;

				dat[arr[sindex]]--;
				sindex++;
			}
		}

		eindex++;

		answer = max(answer, eindex - sindex);
	}


}

int main() {

	input();

	solution();

	cout << answer;
}