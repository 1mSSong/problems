#include <iostream>
using namespace std;

bool same(int, int);
int max(int A, int B, int C);

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	bool res1, res2;
	res1 = (same(A, B) && same(B, C) && same(C, A));
	res2 = (same(A, B) || same(B, C) || same(C, A));
	int price = 0;
	if (res1) {
		price = 10000 + A * 1000;
	}
	else {
		if (!res2) {
			price = max(A, B, C) * 100;
		}
		else {
			if (A == B) price = 1000 + A * 100;
			else if (B == C) price = 1000 + B * 100;
			else price = 1000 + C * 100;
		}

	}
	cout << price;

}

bool same(int A, int B) {
	return A == B;
}

int max(int A, int B, int C) {
	int max = A;
	if (B > max) max = B;
	if (C > max) max = C;
	return max;
}