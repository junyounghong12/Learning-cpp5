#include <iostream>
#include <string>
using namespace std;

class Container { // �� �ϳ��� ��Ÿ���� Ŭ����
	int size; // ���� ���� ��, �ִ� ���差�� 10
public:
	Container() { size = 10; }
	void fill() { size = 10; } // �ִ뷮(10)���� ä���
	void consume() { size--; } // 1 ��ŭ �Ҹ��ϱ�
	int getSize() { return size; } // ���� ũ�� ����
};

class CoffeeVendingMachine { // Ŀ�����Ǳ⸦ ǥ���ϴ� Ŭ����
	Container tong[3]; // tong[0]�� Ŀ��, tong[1]�� ��, tong[2]�� �������� ��Ÿ��
	void fill() { // 3���� ���� ��� 10���� ä��
		for (int i = 0; i < 3; i++) {
			tong[i].fill(); // �迭 �ε��� ���
		}
		show();
	}
	void selectEspresso() { // ���������Ҹ� ������ ���, Ŀ�� 1, �� 1 �Ҹ�
		if (tong[0].getSize() < 1 || tong[1].getSize() < 1) {
			cout << "���ᰡ �����մϴ�." << endl;
		}
		else {
			tong[0].consume();
			tong[1].consume();
			cout << "���������� �弼��" << endl;
		}
	}
	void selectAmericano() { // �Ƹ޸�ī�븦 ������ ���, Ŀ�� 1, �� 2 �Ҹ�
		if (tong[0].getSize() < 1 || tong[1].getSize() < 2) {
			cout << "���ᰡ �����մϴ�." << endl;
		}
		else {
			tong[0].consume();
			tong[1].consume();
			tong[1].consume();
			cout << "�Ƹ޸�ī�� �弼��" << endl;
		}
	}
	void selectSugarcoffee() { // ����Ŀ�Ǹ� ������ ���, Ŀ�� 1, �� 2 �Ҹ�, ���� 1 �Ҹ�
		if (tong[0].getSize() < 1 || tong[1].getSize() < 2 || tong[2].getSize() < 1) {
			cout << "���ᰡ �����մϴ�." << endl;
		}
		else {
			tong[0].consume();
			tong[1].consume();
			tong[1].consume();
			tong[2].consume();
			cout << "����Ŀ�� �弼��" << endl;
		}
	}
	void show() { // ���� Ŀ��, ��, ������ �ܷ� ���
		cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << endl;
	}
public:
	void run() { // Ŀ�� ���Ǳ� �۵�
		cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
		while (1) {
			cout << "�޴��� �����ּ���(0:����, 1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���)>> ";
			int menu;
			cin >> menu; //�޴� ��ȣ �Է�

			switch (menu) {
			case 0:
				cout << "Ŀ�����Ǳ� �۵��� �����մϴ�." << endl;
				return; // ����
			case 1:
				selectEspresso();
				break;
			case 2:
				selectAmericano();
				break;
			case 3:
				selectSugarcoffee();
				break;
			case 4:
				show();
				break;
			case 5:
				fill();
				break;
			}
		}
	}
};

int main() {
	CoffeeVendingMachine prog;
	prog.run();
	return 0;
}