#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl; // 지시문

	while (1) {
		// 빈칸을 포함하는 문자열을 입력
		cout << ">>";
		getline(cin, text, '\n'); // getline() 함수 이용

		if (text == "exit")
			break; //exit를 입력하면 종료

		int size = text.size(); // 문자열 길이를 size 변수에 저장
		for (int i = 0; i < (size / 2); i++) { // 문자열 절반 길이만큼 반복
			// 문자열의 앞문자과 뒷문자를 서로 바꿈
			char temp = text[i]; 
			text[i] = text[size - i - 1];
			text[size - i - 1] = temp;
		}
		cout << text << endl; // 수정된 문자열 출력
	}
	return 0;
}