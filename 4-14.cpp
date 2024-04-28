#include <iostream>
#include <string>
#include <cstdlib> // rand(), srand() ���
#include <ctime> // time() ���
using namespace std;

class Player {
	string name; // �̸�
public:
	int num[3]; // 3���� �� ������ �迭
	void set(string name) { this->name = name; } // �̸� ����
	string getName() { return name; } // �̸� ��ȯ
};

class GamblingGame {
	Player p[2]; // ���� 2�� �迭
	int turn(int index) { // �� �� ����
		cout << p[index].getName() << ":<ENTER>";
		int enter = getchar(); // �Է�

		if (enter == '\n') { // ���� �Է�
			cout << "\t\t";
			for (int i = 0; i < 3; i++) {
				p[index].num[i] = rand() % 3; // 0���� 2������ ������ 3���� �� ����, �迭�� ����
				cout << p[index].num[i] << '\t'; // ������ 3���� �� ���
			}
			if (p[index].num[0] == p[index].num[1] && p[index].num[1] == p[index].num[2]) { // 3���� �� ��ġ
				cout << p[index].getName() << "�� �¸�!!" << endl;	// �¸� ��� ���
				return 0; //����
			}
			else {
				cout << "�ƽ�����!" << endl;
				return 1; //���� ���
			}
		}
	}
public:
	GamblingGame() { srand((unsigned)time(NULL)); } // ���� �ʱ�ȭ
	void game() { // ���� ����
		cout << "***** ���� ������ �����մϴ�. *****" << endl;
		string name;
		cout << "ù��° ���� �̸�>>";
		getline(cin, name); // ù��° ���� �̸� �Է�
		p[0].set(name); // ù��° ���� �̸� ����
		cout << "�ι�° ���� �̸�>>";
		getline(cin, name); // �ι�° ���� �̸� �Է�
		p[1].set(name); // �ι�° ���� �̸� ����

		int index = 0;
		int result = 1;
		while (result == 1) { // result == 1�̸� ���� ���
			result = turn(index); // ����� ���� result ������
			index = (index + 1) % 2; // ���� ����
		}
	}
};

int main() {
	GamblingGame gamble;
	gamble.game();
	return 0;
}