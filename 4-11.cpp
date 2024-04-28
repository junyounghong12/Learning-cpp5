#include <iostream>
#include <string>
using namespace std;

class Container { // 통 하나를 나타내는 클래스
	int size; // 현재 저장 량, 최대 저장량은 10
public:
	Container() { size = 10; }
	void fill() { size = 10; } // 최대량(10)으로 채우기
	void consume() { size--; } // 1 만큼 소모하기
	int getSize() { return size; } // 현재 크기 리턴
};

class CoffeeVendingMachine { // 커피자판기를 표현하는 클래스
	Container tong[3]; // tong[0]는 커피, tong[1]은 물, tong[2]는 설탕통을 나타냄
	void fill() { // 3개의 통을 모두 10으로 채움
		for (int i = 0; i < 3; i++) {
			tong[i].fill(); // 배열 인덱스 사용
		}
		show();
	}
	void selectEspresso() { // 에스프레소를 선택한 경우, 커피 1, 물 1 소모
		if (tong[0].getSize() < 1 || tong[1].getSize() < 1) {
			cout << "원료가 부족합니다." << endl;
		}
		else {
			tong[0].consume();
			tong[1].consume();
			cout << "에스프레소 드세요" << endl;
		}
	}
	void selectAmericano() { // 아메리카노를 선택한 경우, 커피 1, 물 2 소모
		if (tong[0].getSize() < 1 || tong[1].getSize() < 2) {
			cout << "원료가 부족합니다." << endl;
		}
		else {
			tong[0].consume();
			tong[1].consume();
			tong[1].consume();
			cout << "아메리카노 드세요" << endl;
		}
	}
	void selectSugarcoffee() { // 설탕커피를 선택한 경우, 커피 1, 물 2 소모, 설탕 1 소모
		if (tong[0].getSize() < 1 || tong[1].getSize() < 2 || tong[2].getSize() < 1) {
			cout << "원료가 부족합니다." << endl;
		}
		else {
			tong[0].consume();
			tong[1].consume();
			tong[1].consume();
			tong[2].consume();
			cout << "설탕커피 드세요" << endl;
		}
	}
	void show() { // 현재 커피, 물, 설탕의 잔량 출력
		cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
	}
public:
	void run() { // 커피 자판기 작동
		cout << "***** 커피자판기를 작동합니다. *****" << endl;
		while (1) {
			cout << "메뉴를 눌러주세요(0:종료, 1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
			int menu;
			cin >> menu; //메뉴 번호 입력

			switch (menu) {
			case 0:
				cout << "커피자판기 작동을 종료합니다." << endl;
				return; // 종료
			case 1:
				selectEspresso();
				break;
			case 2:
				selectAmericano();
				break;
			case 3:
				selectSugarcoffee();
				break;
			case 4:
				show();
				break;
			case 5:
				fill();
				break;
			}
		}
	}
};

int main() {
	CoffeeVendingMachine prog;
	prog.run();
	return 0;
}