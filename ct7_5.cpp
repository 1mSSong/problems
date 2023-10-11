#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end) {
	if (start > end)
		return -1;

	int mid = (start + end) / 2;

	if (arr[mid] == target)
		return mid;

	else if (arr[mid] > target)
		return binarySearch(arr, target, start, mid - 1);
	else
		return binarySearch(arr, target, mid + 1, end);
}

int n, m;
vector<int> nthing, mthing;

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nthing.push_back(x);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		mthing.push_back(x);
	}

	sort(nthing.begin(), nthing.end());

	for (int i = 0; i < m; i++) {
		if (binarySearch(nthing, mthing[i], 0, n - 1) == -1)
			cout << "no ";
		else
			cout << "yes ";
	}
}