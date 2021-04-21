/* Paige Mabbitt
Febuary 18th, 2021
Mastermind
This is all my own work
*/
#include "Game.h"
#include "Guess.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	//Initialize class game and guess
	Game game;
	Guess guess;
	//create array with code numbers
	int* code = game.generateCode();

	//!!For Testing!!
	/*string fullCode;
	for (int x = 0; x < 5; x++) {
		fullCode += to_string(code[x]);
	}
	cout << fullCode << endl;*/

	//print rules to the user
	cout << "Rules: Try to guess the secret code! The code will be 5 numbers long and use only numbers 1-5. (Please add a space between numbers when inputting)." << endl;
	cout << "White pegs are correct number but incorrect spots and black pegs are correct numbers and spots. Good Luck!" << endl;
	//while the user has not lost the game
	while (game.checkLose(game.getLives()) != true) {
		//get user input
		guess.getInput();
		//check the guess
		guess.checkGuess(code);
		//set the lives for the next round
		game.setLives();
	}
}