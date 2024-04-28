#include <iostream>
using namespace std;

int main() {
	int* n = new int[5]; // new 연산자로 배열 형태 메모리 동적할당

	cout << "정수 5개 입력 >> "; // 지시문 출력
	for (int i = 0; i < 5; i++) { // for문 이용해 5번 입력
		cin >> n[i]; // 배열 인덱스 사용
	}

	double average = n[0];
	for (int i = 1; i < 5; i++) {
		average += n[i];
	}
	average /= 5; // 평균
	cout << "평균 " << average << endl; // 평균 출력

	delete[] n; // delete 연산자로 배열 형태 메모리 할당해제
	return 0;
}