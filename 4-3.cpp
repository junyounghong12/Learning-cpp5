#include <iostream>
#include <string>
using namespace std;

int main() {
	// ��ĭ�� �����ϴ� ���ڿ��� �Է�
	string text;
	cout << "���ڿ� �Է� >> ";
	getline(cin, text, '\n'); // getline() �Լ� �̿�

	// 1)���ڿ�����'a'�� ã�� ���� string Ŭ������ ��� at() �� []�� �̿��Ͽ� �ۼ�
	int n = 0; // 'a' ������ ���� ����
	int size = text.size(); // ���ڿ� ���̸� size ������ ����
	for (int i = 0; i < size; i++) { // for������ ���ڿ� ���̸�ŭ �ݺ�
		if (text[i] == 'a') // []�� �̿�
			n++;
	}
	cout << "���� a�� " << n << "�� �ֽ��ϴ�." << endl; // ��� ���

	// 2)���ڿ�����'a'�� ã�� ���� string Ŭ������ find() ��� �Լ��� �̿��Ͽ� �ۼ�
	n = 0;
	int index =text.find('a'); // find() ��� �Լ��� �̿�
	while (index != string::npos) { // 'a'�� ã�� �� ���� ������ �ݺ�
		n++;
		index = text.find('a', index + 1); // ���������� ã�� 'a'�� ���� ��ġ
	}
	cout << "���� a�� " << n << "�� �ֽ��ϴ�." << endl; // ��� ���

	return 0;
}