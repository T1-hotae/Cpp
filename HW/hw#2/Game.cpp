#include <iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

#include "Game.h"

Player::Player(string playername) {
	player = playername;
}
void Player::randomDice() {
	for (int i = 0; i < 3; i++) {
		dice[i] = rand() % 3;
	}
}
void Player::diceResult() {
	for (int i = 0; i < 3; i++) {
		cout << dice[i] << " ";
	}
}

bool Player::diceCheck() {
	return (dice[0] == dice[1]) && (dice[1] == dice[2]);
}

string Player::getName() {
	return player;
}

GamblingGame::GamblingGame(string player1Name, string player2Name) {
	players[0] = new Player(player1Name);
	players[1] = new Player(player2Name);

}
void GamblingGame::play() {
    int turn = 0;
    while (true) {
        cout << players[turn]->getName() << ": <Enter>";
        cin.ignore();

        players[turn]->randomDice();
        players[turn]->diceResult();

        if (players[turn]->diceCheck()) {
            cout << players[turn]->getName() << "님 승리!!" << endl;
            break;
        }
        else {
            cout << "아쉽군요!" << endl;
        }
        turn = (turn + 1) % 2;
    }
}
GamblingGame::~GamblingGame(){
	delete players[0];
	delete players[1];
}
