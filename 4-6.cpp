#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl; // ���ù�

	while (1) {
		// ��ĭ�� �����ϴ� ���ڿ��� �Է�
		cout << ">>";
		getline(cin, text, '\n'); // getline() �Լ� �̿�

		if (text == "exit")
			break; //exit�� �Է��ϸ� ����

		int size = text.size(); // ���ڿ� ���̸� size ������ ����
		for (int i = 0; i < (size / 2); i++) { // ���ڿ� ���� ���̸�ŭ �ݺ�
			// ���ڿ��� �չ��ڰ� �޹��ڸ� ���� �ٲ�
			char temp = text[i]; 
			text[i] = text[size - i - 1];
			text[size - i - 1] = temp;
		}
		cout << text << endl; // ������ ���ڿ� ���
	}
	return 0;
}