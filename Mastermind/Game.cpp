/* Paige Mabbitt
Febuary 18th, 2021
Mastermind
This is all my own work
*/
#include "Game.h"
#include <iostream>
#include <time.h>
#include <string>

Game::Game()
{
	//initialize code and lives
	code;
	lives = 10;
}

int* Game::generateCode()
{
	//seed rand
	srand(time(NULL));
	//create a random number between 1 and 5 and put into a array of 5
	for (int x = 0; x < 5; x++) {
		code[x] = (rand() % 5 + 1);
	}
	return code;
}

int Game::getLives()
{
	//return live count
	return lives;
}

void Game::setLives()
{
	//subtract one from lives count
	lives = lives - 1;
}

bool Game::checkLose(int lives)
{
	//if the player is out of lives (turns), then they lose
	if (lives == 0) {
		cout << "Out of Lives!" << endl;
		string fullCode = "";
		//put the secret code into a string
		for (int x = 0; x < 5; x++) {
			fullCode += to_string(code[x]);
		}
		//display secret code
		cout << "Here was the secret code: " << fullCode;
		//return true
		return true;
		//exit program
		exit(0);
	}
	//if the player still has lives left
	else {
		//display the amout of lives
		cout << "\nYou have " << lives << " lives left." << endl;
		//return false
		return false;
	}
}