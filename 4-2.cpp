#include <iostream>
using namespace std;

int main() {
	int* n = new int[5]; // new �����ڷ� �迭 ���� �޸� �����Ҵ�

	cout << "���� 5�� �Է� >> "; // ���ù� ���
	for (int i = 0; i < 5; i++) { // for�� �̿��� 5�� �Է�
		cin >> n[i]; // �迭 �ε��� ���
	}

	double average = n[0];
	for (int i = 1; i < 5; i++) {
		average += n[i];
	}
	average /= 5; // ���
	cout << "��� " << average << endl; // ��� ���

	delete[] n; // delete �����ڷ� �迭 ���� �޸� �Ҵ�����
	return 0;
}