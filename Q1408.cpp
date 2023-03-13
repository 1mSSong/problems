#include <iostream>
#include <string>
using namespace std;

struct Time{
	int h, m, s;
};

int findSum(Time t) {
	int sum = t.h * 3600 + t.m * 60 + t.s;
	return sum;
}

int main() {
	Time now, mission;

	scanf("%d:%d:%d", &now.h, &now.m, &now.s);
	scanf("%d:%d:%d", &mission.h, &mission.m, &mission.s);

	int nowSum = findSum(now);
	int missionSum = findSum(mission);

	int tmp = missionSum - nowSum;

	if (nowSum < missionSum) {
		printf("%02d:%02d:%02d", tmp / 3600, tmp % 3600 / 60, tmp % 60);
	}
	else {
		tmp = 24 * 3600 - nowSum + missionSum;
		printf("%02d:%02d:%02d", tmp / 3600, tmp % 3600 / 60, tmp % 60);
	}
}