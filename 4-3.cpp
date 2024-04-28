#include <iostream>
#include <string>
using namespace std;

int main() {
	// 빈칸을 포함하는 문자열을 입력
	string text;
	cout << "문자열 입력 >> ";
	getline(cin, text, '\n'); // getline() 함수 이용

	// 1)문자열에서'a'를 찾기 위해 string 클래스의 멤버 at() 나 []를 이용하여 작성
	int n = 0; // 'a' 개수를 세는 변수
	int size = text.size(); // 문자열 길이를 size 변수에 저장
	for (int i = 0; i < size; i++) { // for문으로 문자열 길이만큼 반복
		if (text[i] == 'a') // []를 이용
			n++;
	}
	cout << "문자 a는 " << n << "개 있습니다." << endl; // 결과 출력

	// 2)문자열에서'a'를 찾기 위해 string 클래스의 find() 멤버 함수를 이용하여 작성
	n = 0;
	int index =text.find('a'); // find() 멤버 함수를 이용
	while (index != string::npos) { // 'a'를 찾을 수 없을 때까지 반복
		n++;
		index = text.find('a', index + 1); // 마지막으로 찾은 'a'의 다음 위치
	}
	cout << "문자 a는 " << n << "개 있습니다." << endl; // 결과 출력

	return 0;
}