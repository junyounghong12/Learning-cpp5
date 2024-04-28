#include <iostream>
using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) { // 생성자
		size = n; p = new int[n]; // n개 정수 배열의 동적 생성
	}
	void read(); // 동적 할당받은 정수 배열 p에 사용자로부터 정수를 입력 받음
	void write(); // 정수 배열을 화면에 출력
	int big(); // 정수 배열에서 가장 큰 수 리턴
	~Sample(); // 소멸자
};

void Sample::read() {
	for (int i = 0; i < size; i++) //for문 반복
		cin >> p[i]; // 동적 할당받은 정수 배열 p에 사용자로부터 정수를 입력 받음
}

void Sample::write() {
	for (int i = 0; i < size; i++)
		cout << p[i] << ' '; // 정수 배열 출력
	cout << endl;
}

int Sample::big() {
	int b = p[0];
	//정수 배열에서 가장 큰 수 찾기
	for (int i = 1; i < size; i++) {
		if (b < p[i])
			b = p[i];
	}
	return b; // 정수 배열에서 가장 큰 수 리턴
}

Sample::~Sample() { // 소멸자
	delete[] p; // delete 연산자
}

int main() {
	Sample s(10); // 10개 정수 배열을 가진 Sample 객체 생성
	s.read(); // 키보드에서 정수 배열 읽기
	s.write(); // 정수 배열 출력
	cout << "가장 큰 수는 " << s.big() << endl; // 가장 큰 수 출력
}