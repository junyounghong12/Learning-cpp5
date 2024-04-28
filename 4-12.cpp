#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius; // 원의 반지름 값
	string name; // 원의 이름
public:
	void setCircle(string name, int radius) { // 이름과 반지름 설정
		this->name = name; this->radius = radius; 
	}
	double getArea() { 
		return 3.14 * radius * radius; 
	}
	string getName() { 
		return name; 
	}
};

class CircleManager {
	Circle *p; // Circle 배열에 대한 포인터
	int size; // 배열의 크기
public:
	CircleManager(int size) { // size 크기의 배열을 동적 생성. 사용자로부터 입력 완료
		this->size = size;
		p = new Circle[size];
	}

	void setCircle(int index, string name, int radius) {
		p[index].setCircle(name, radius); //배열 인덱스 사용
	}

	~CircleManager() { delete[] p; }

	void searchByName() { // 사용자로부터 원의 이름을 입력받아 면적 출력
		string sname;
		int index;
		cout << "검색하고자 하는 원의 이름 >> ";
		cin >> sname;
		for (int i = 0; i < size; i++) {
			if ((p + i)->getName() == sname) { //조건문, 포인터 연산과 간접 멤버 접근 연산자 사용
				index = i;
				cout << sname << "의 면적은 " << (p + index)->getArea() << endl;
				break;
			}
		}
	}

	void searchByArea() { // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
		int min;
		cout << "최소 면적을 정수로 입력하세요 >> ";
		cin >> min;
		cout << min << "보다 큰 원을 검색합니다." << endl;
		for (int i = 0; i < size; i++) {
			if (p[i].getArea() > min) { //조건문, 배열 인덱스 사용
				cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ",";
			}
		}
		cout << endl;
	}
};

int main() {
	int n;
	cout << "원의 개수 >> ";
	cin >> n; //원의 개수 입력
	CircleManager a(n);
	int radius;
	string name;
	for (int i = 0; i < n; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> name >> radius; //원의 이름과 반지름을 입력
		a.setCircle(i, name, radius);
	}
	a.searchByName();
	a.searchByArea();

	return 0;
}