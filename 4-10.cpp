#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person();
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void set(string name);
};
Person::Person() {
	name = "noname"; //초기화
}
void Person::set(string name) { // 이름 설정 멤버 함수
	this->name = name;
}

class Family {
	string name;
	Person* p; // Person 배열 포인터
	int size; // Person 배열의 크기. 가족 구성원 수
public:
	Family(string name, int size); // size 개수만큼 Person 배열 동적 생성
	void set(int index, string name);
	void show(); // 모든 가족 구성원 출력
	~Family();
};
Family::Family(string name, int size) {
	this->name = name;
	this->size = size;
	p = new Person[size];
}
void Family::set(int index, string name) {
	(p + index)->set(name); // 포인터 연산과 간접 멤버 접근 연산자 사용
}
void Family::show() {
	cout << this->name << " 가족은 다음과 같이 " << this->size << "명 입니다." << endl;
	for (int i = 0; i < (this->size); i++) {
		cout << p[i].getName() << '\t'; // 배열 인덱스 사용
	}
	cout << endl;
}
Family::~Family() {
	delete[] p;
}

int main() {
	Family* simpson = new Family("Simpson", 3); // 3명으로 구성된 Simpson 가족
	simpson->set(0, "Mr. Simpson");
	simpson->set(1, "Mrs. Simpson");
	simpson->set(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}