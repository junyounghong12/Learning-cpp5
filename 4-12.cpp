#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius; // ���� ������ ��
	string name; // ���� �̸�
public:
	void setCircle(string name, int radius) { // �̸��� ������ ����
		this->name = name; this->radius = radius; 
	}
	double getArea() { 
		return 3.14 * radius * radius; 
	}
	string getName() { 
		return name; 
	}
};

class CircleManager {
	Circle *p; // Circle �迭�� ���� ������
	int size; // �迭�� ũ��
public:
	CircleManager(int size) { // size ũ���� �迭�� ���� ����. ����ڷκ��� �Է� �Ϸ�
		this->size = size;
		p = new Circle[size];
	}

	void setCircle(int index, string name, int radius) {
		p[index].setCircle(name, radius); //�迭 �ε��� ���
	}

	~CircleManager() { delete[] p; }

	void searchByName() { // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
		string sname;
		int index;
		cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
		cin >> sname;
		for (int i = 0; i < size; i++) {
			if ((p + i)->getName() == sname) { //���ǹ�, ������ ����� ���� ��� ���� ������ ���
				index = i;
				cout << sname << "�� ������ " << (p + index)->getArea() << endl;
				break;
			}
		}
	}

	void searchByArea() { // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸� ���
		int min;
		cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
		cin >> min;
		cout << min << "���� ū ���� �˻��մϴ�." << endl;
		for (int i = 0; i < size; i++) {
			if (p[i].getArea() > min) { //���ǹ�, �迭 �ε��� ���
				cout << p[i].getName() << "�� ������ " << p[i].getArea() << ",";
			}
		}
		cout << endl;
	}
};

int main() {
	int n;
	cout << "���� ���� >> ";
	cin >> n; //���� ���� �Է�
	CircleManager a(n);
	int radius;
	string name;
	for (int i = 0; i < n; i++) {
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
		cin >> name >> radius; //���� �̸��� �������� �Է�
		a.setCircle(i, name, radius);
	}
	a.searchByName();
	a.searchByArea();

	return 0;
}