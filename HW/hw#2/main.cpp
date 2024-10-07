#include <iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

#include "Game.h"

int main() {

	string player1, player2;
	
	srand((unsigned)time(0));	//랜덤 숫자 생성

	cout << "***** 겜블링 게임을 시작합니다. *****" << endl;

	cout << "첫번째 선수 이름 >>";
	getline(cin, player1);
	cout << "두번째 선수 이름 >>";
	getline(cin, player2);

	GamblingGame setPlayer(player1, player2);	//player class를 통해서
	setPlayer.play();	//게임시작
}
