#include <iostream>
using namespace std;

class Circle {
	int radius; // ���� ������ ��
public:
	void setRadius(int r); // �������� �����Ѵ�.
	double getArea(); // ������ �����Ѵ�.
};
void Circle::setRadius(int r) {
	radius = r;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle* n = new Circle[3]; // �迭 ���� �޸� �����Ҵ�, 3���� Circle ��ü�� ���� �迭 ����
	int c = 0; // ������ 100���� ū ���� ������ ���� ����
	int r;

	for (int i = 0; i < 3; i++) {
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> r; // ���� ������ �Է�
		n[i].setRadius(r); //�迭 �ε��� ���

		if ((n + i)->getArea() > 100) //������ ����� ���� ��� ���� ������ ���
			c++; // ������ 100���� ũ�� ���� c ����
	}
	cout << "������ 100���� ū ���� " << c << "�� �Դϴ�" << endl; // ������ 100���� ū ���� ���� ���

	delete[] n; // �迭 ���� �޸� �Ҵ�����
	return 0;
}