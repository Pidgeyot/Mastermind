/* Paige Mabbitt
Febuary 18th, 2021
Mastermind
This is all my own work
*/
#include "Guess.h"
#include <iostream>

Guess::Guess()
{
	guess;
}

void Guess::getInput()
{
	//ask the user for their guess
	cout << "Please input your guess" << endl;
	//put the next five inputs into the guess array
	cin >> guess[0] >> guess[1] >> guess[2] >> guess[3] >> guess[4];
}

void Guess::checkGuess(int* code)
{
	//set win to 0
	int win = 0;
	//for the size of the code array, check each element in code against the same spot element in guess
	for (int i = 0; i < sizeof(code); i++) {
		//if the elements are the same
		if (code[i] == guess[i]) {
			//add one to win
			win += 1;
		}
	}
	//if all elements are the same
	if (win == sizeof(code)) {
		//user win, exit program
		cout << "You win!" << endl;
		exit(0);
	}
	//if its not the same
	else {
		//give the user feedback
		giveFeedback(code);
	}
}

void Guess::giveFeedback(int* code)
{
	//set black and white pegs to zero
	int blackPegs = 0;
	int whitePegs = 0;

	//for the size of code, check each element in the same spot of each array for similarities
	for (int i = 0; i < sizeof(*code); i++) {
		//if they are the same
		if (code[i] == guess[i]) {
			//add one to bleck peg
			blackPegs += 1;
		}
	}

	//array length needs to be as long as the highest value guess
	//initialize code color positions array
	int codeColorPos[5] = { 0, 0, 0, 0,0 };
	//for the size of code array
	for (int i = 0; i < sizeof(*code); i++) {
		//add one for each number type in code array
		//ie: if there are 2 4's in the code, add 2 to the 4 position in code color position
		codeColorPos[code[i] - 1] += 1;
	}
	//initialize guess color position array
	int guessColorPos[5] = { 0, 0, 0, 0,0 };
	//for the size of guess array
	for (int i = 0; i < sizeof(*guess); i++) {
		//add one for each number type in guess array
		//ie: if there are 1 3 in the code, add 1 to the 3 position in guess color position
		guessColorPos[guess[i] - 1] += 1;
	}
	//for the size of code color positions
	for (int i = 0; i < sizeof(*codeColorPos); i++) {
		//if the amount in code is more than in guess
		if (codeColorPos[i] > guessColorPos[i]) {
			//white pegs == to amount in guess
			whitePegs += guessColorPos[i];
		}
		else {
			//white pegs == to amount in color
			whitePegs += codeColorPos[i];
		}
	}
	//subtract black pegs from white pegs for the total white pegs
	whitePegs = whitePegs - blackPegs;

	//print out the number of white and black pegs
	cout << "Incorrect! You have " << whitePegs << " white pegs and " << blackPegs << " black pegs" << endl;
}