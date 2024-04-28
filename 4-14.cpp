#include <iostream>
#include <string>
#include <cstdlib> // rand(), srand() 사용
#include <ctime> // time() 사용
using namespace std;

class Player {
	string name; // 이름
public:
	int num[3]; // 3개의 수 저장할 배열
	void set(string name) { this->name = name; } // 이름 설정
	string getName() { return name; } // 이름 반환
};

class GamblingGame {
	Player p[2]; // 선수 2명 배열
	int turn(int index) { // 한 턴 진행
		cout << p[index].getName() << ":<ENTER>";
		int enter = getchar(); // 입력

		if (enter == '\n') { // 엔터 입력
			cout << "\t\t";
			for (int i = 0; i < 3; i++) {
				p[index].num[i] = rand() % 3; // 0에서 2사이의 랜덤한 3개의 수 생성, 배열에 저장
				cout << p[index].num[i] << '\t'; // 랜덤한 3개의 수 출력
			}
			if (p[index].num[0] == p[index].num[1] && p[index].num[1] == p[index].num[2]) { // 3개의 수 일치
				cout << p[index].getName() << "님 승리!!" << endl;	// 승리 결과 출력
				return 0; //종료
			}
			else {
				cout << "아쉽군요!" << endl;
				return 1; //게임 계속
			}
		}
	}
public:
	GamblingGame() { srand((unsigned)time(NULL)); } // 난수 초기화
	void game() { // 게임 진행
		cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
		string name;
		cout << "첫번째 선수 이름>>";
		getline(cin, name); // 첫번째 선수 이름 입력
		p[0].set(name); // 첫번째 선수 이름 설정
		cout << "두번째 선수 이름>>";
		getline(cin, name); // 두번째 선수 이름 입력
		p[1].set(name); // 두번째 선수 이름 설정

		int index = 0;
		int result = 1;
		while (result == 1) { // result == 1이면 게임 계속
			result = turn(index); // 결과에 따라 result 정해짐
			index = (index + 1) % 2; // 선수 변경
		}
	}
};

int main() {
	GamblingGame gamble;
	gamble.game();
	return 0;
}