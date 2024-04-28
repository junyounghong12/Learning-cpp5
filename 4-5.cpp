#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	string text;
	cout << "아래에 한 줄을 입력하세요. (exit를 입력하면 종료합니다)" << endl; //지시문

	while (1) {
		// 빈칸을 포함하는 문자열을 입력
		cout << ">>";
		getline(cin, text, '\n'); // getline() 함수 이용

		if (text == "exit")
			break; //exit를 입력하면 종료

		int size = text.size(); // 문자열 길이를 size 변수에 저장
		srand((unsigned)time(NULL)); // 시작할 때마다, 다른 랜덤수를 발생시키기 위한 seed 설정
		int n = rand() % size; // 0에서 size-1 사이의 랜덤한 정수 발생

		string eng = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // 영문자
		int engsize = eng.size(); // 영문자 개수
		text[n] = eng[rand() % engsize]; // 글자 하나만 랜덤하게 수정 
		cout << text << endl; // 수정된 문자열 출력
	}
	return 0;
}