#include <iostream>
using namespace std;

class Circle {
	int radius; // 원의 반지름 값
public:
	void setRadius(int r); // 반지름을 설정한다.
	double getArea(); // 면적을 리턴한다.
};
void Circle::setRadius(int r) {
	radius = r;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle* n = new Circle[3]; // 배열 형태 메모리 동적할당, 3개의 Circle 객체를 가진 배열 선언
	int c = 0; // 면적이 100보다 큰 원의 개수를 세는 변수
	int r;

	for (int i = 0; i < 3; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r; // 원의 반지름 입력
		n[i].setRadius(r); //배열 인덱스 사용

		if ((n + i)->getArea() > 100) //포인터 연산과 간접 멤버 접근 연산자 사용
			c++; // 면적이 100보다 크면 변수 c 증가
	}
	cout << "면적이 100보다 큰 원은 " << c << "개 입니다" << endl; // 면적이 100보다 큰 원의 개수 출력

	delete[] n; // 배열 형태 메모리 할당해제
	return 0;
}