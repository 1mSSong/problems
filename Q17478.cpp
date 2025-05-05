#include <iostream>
#include <string>
using namespace std;

int n;

void input() {
	cin >> n;
}

void printUnder(int level) {
	for (int i = 0; i < 4 * level; ++i) {
		cout << "_";
	}
}

void dfs(int level) {
	if (level == n) {
		printUnder(level);
		cout << "\"����Լ��� ������?\"\n";
		printUnder(level);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		printUnder(level);
		cout << "��� �亯�Ͽ���.\n";
		return;
	}
	
	printUnder(level);
	cout << "\"����Լ��� ������?\"\n";
	printUnder(level);
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	printUnder(level);
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	printUnder(level);
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

	dfs(level + 1);

	printUnder(level);
	cout << "��� �亯�Ͽ���.\n";
}

void solution() {
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.";
	cout << "\n";
	dfs(0);
}

int main() {
	input();

	solution();
}