#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};
Person::Person() {
	name = "noname";
	tel = "000-0000-0000";
}
void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	Person* n = new Person[3]; // 3개의 Person 객체를 가지는 배열 선언

	cout << "이름과 전화 번호를 입력해 주세요" << endl; // 지시문
	for (int i = 0; i < 3; i++) {
		string name, tel;
		cout << "사람 " << i + 1 << ">> ";
		cin >> name >> tel; // 이름 전화 번호 입력
		n[i].set(name, tel); // 배열 인덱스 사용
	}

	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) {
		cout << n[i].getName() << ' '; // 이름 출력
	}
	cout << endl;

	string sname;
	int index;
	cout << "전화번호 검색합니다. 이름을 입력하세요>>";
	cin >> sname;
	for (int i = 0; i < 3; i++){ 
		if ((n + i)->getName() == sname) { //포인터 연산과 간접 멤버 접근 연산자 사용
			index = i;
			cout << "전화 번호는 " << (n + index)->getTel() << endl;
			break; // 반복문 탈출
		}
	}
	
	delete[] n; // 배열 형태 메모리 할당해제
	return 0;
}