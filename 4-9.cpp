#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};
Person::Person() {
	name = "noname";
	tel = "000-0000-0000";
}
void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	Person* n = new Person[3]; // 3���� Person ��ü�� ������ �迭 ����

	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl; // ���ù�
	for (int i = 0; i < 3; i++) {
		string name, tel;
		cout << "��� " << i + 1 << ">> ";
		cin >> name >> tel; // �̸� ��ȭ ��ȣ �Է�
		n[i].set(name, tel); // �迭 �ε��� ���
	}

	cout << "��� ����� �̸��� ";
	for (int i = 0; i < 3; i++) {
		cout << n[i].getName() << ' '; // �̸� ���
	}
	cout << endl;

	string sname;
	int index;
	cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
	cin >> sname;
	for (int i = 0; i < 3; i++){ 
		if ((n + i)->getName() == sname) { //������ ����� ���� ��� ���� ������ ���
			index = i;
			cout << "��ȭ ��ȣ�� " << (n + index)->getTel() << endl;
			break; // �ݺ��� Ż��
		}
	}
	
	delete[] n; // �迭 ���� �޸� �Ҵ�����
	return 0;
}