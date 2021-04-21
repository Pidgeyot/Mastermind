/* Paige Mabbitt
Febuary 18th, 2021
Mastermind
This is all my own work
*/
#ifndef GUESS_H
#define GUESS_H
#include <string>
#include <vector>
using namespace std;

class Guess
{
private:
	int guess[5];
public:
	Guess();
	void getInput();
	void checkGuess(int* code);
	void giveFeedback(int* code);
};

#endif GUESS_H
