#pragma once
class Player {	//player 고유의 데이터를 저장
	string player;
	int dice[3] = { 0 };
public:
	Player(string player);
	void randomDice();
	void diceResult();
	bool diceCheck();
	string getName();
};
class GamblingGame {	//player 고유의 데이터를 가지고 게임 만들기
	Player* players[2];
public:
	GamblingGame(string player1Name, string player2Name);
	void play();
	~GamblingGame();
};
