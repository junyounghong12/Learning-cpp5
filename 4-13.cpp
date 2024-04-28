#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string text;
	int h[26];
public:
	Histogram() {
		text = "notext";
	}
	Histogram(string text) { 
		this->text = text; 
	}
	void put(string text) {
		this->text += text;
	}
	void putc(char c) {
		this->text += c;
	}
	void print() {
		cout << text << endl; // �ؽ�Ʈ ���

		for (int i = 0; i < 26; i++) {
			h[i] = 0;
		}
		for (char c : text) { // ���ĺ� �󵵼� ���
			if (isalpha(c))
				h[tolower(c) - 'a']++;
		}

		int sum = 0;
		for (int i = 0; i < 26; i++) {
			sum += h[i]; // �� ���ĺ� ��
		}
		cout << "�� ���ĺ� �� " << sum << endl; // �� ���ĺ� �� ���

		for (int i = 0; i < 26; i++) { //�ݺ���
			cout << char('a' + i) << " (" << h[i] << ")" << '\t' << ": ";
			for (int j = 0; j < h[i]; j++)
				cout << '*'; // * ��� ���
			cout << endl;
		}
	}
};

int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, \n");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}