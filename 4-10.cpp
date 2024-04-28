#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person();
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void set(string name);
};
Person::Person() {
	name = "noname"; //�ʱ�ȭ
}
void Person::set(string name) { // �̸� ���� ��� �Լ�
	this->name = name;
}

class Family {
	string name;
	Person* p; // Person �迭 ������
	int size; // Person �迭�� ũ��. ���� ������ ��
public:
	Family(string name, int size); // size ������ŭ Person �迭 ���� ����
	void set(int index, string name);
	void show(); // ��� ���� ������ ���
	~Family();
};
Family::Family(string name, int size) {
	this->name = name;
	this->size = size;
	p = new Person[size];
}
void Family::set(int index, string name) {
	(p + index)->set(name); // ������ ����� ���� ��� ���� ������ ���
}
void Family::show() {
	cout << this->name << " ������ ������ ���� " << this->size << "�� �Դϴ�." << endl;
	for (int i = 0; i < (this->size); i++) {
		cout << p[i].getName() << '\t'; // �迭 �ε��� ���
	}
	cout << endl;
}
Family::~Family() {
	delete[] p;
}

int main() {
	Family* simpson = new Family("Simpson", 3); // 3������ ������ Simpson ����
	simpson->set(0, "Mr. Simpson");
	simpson->set(1, "Mrs. Simpson");
	simpson->set(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}