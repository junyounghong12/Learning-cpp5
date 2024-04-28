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
		cout << text << endl; // ÅØ½ºÆ® Ãâ·Â

		for (int i = 0; i < 26; i++) {
			h[i] = 0;
		}
		for (char c : text) { // ¾ËÆÄºª ºóµµ¼ö °è»ê
			if (isalpha(c))
				h[tolower(c) - 'a']++;
		}

		int sum = 0;
		for (int i = 0; i < 26; i++) {
			sum += h[i]; // ÃÑ ¾ËÆÄºª ¼ö
		}
		cout << "ÃÑ ¾ËÆÄºª ¼ö " << sum << endl; // ÃÑ ¾ËÆÄºª ¼ö Ãâ·Â

		for (int i = 0; i < 26; i++) { //¹Ýº¹¹®
			cout << char('a' + i) << " (" << h[i] << ")" << '\t' << ": ";
			for (int j = 0; j < h[i]; j++)
				cout << '*'; // * °á°ú Ãâ·Â
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