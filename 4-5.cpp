#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	string text;
	cout << "�Ʒ��� �� ���� �Է��ϼ���. (exit�� �Է��ϸ� �����մϴ�)" << endl; //���ù�

	while (1) {
		// ��ĭ�� �����ϴ� ���ڿ��� �Է�
		cout << ">>";
		getline(cin, text, '\n'); // getline() �Լ� �̿�

		if (text == "exit")
			break; //exit�� �Է��ϸ� ����

		int size = text.size(); // ���ڿ� ���̸� size ������ ����
		srand((unsigned)time(NULL)); // ������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����
		int n = rand() % size; // 0���� size-1 ������ ������ ���� �߻�

		string eng = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // ������
		int engsize = eng.size(); // ������ ����
		text[n] = eng[rand() % engsize]; // ���� �ϳ��� �����ϰ� ���� 
		cout << text << endl; // ������ ���ڿ� ���
	}
	return 0;
}