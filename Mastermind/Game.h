/* Paige Mabbitt
Febuary 18th, 2021
Mastermind
This is all my own work
*/
#ifndef GAME_H
#define GAME_H
#include <vector>
using namespace std;

class Game
{
private:
	int code[5];
	int lives;
public:
	Game();
	int* generateCode();
	int getLives();
	void setLives();
	bool checkLose(int lives);

};

#endif GAME_H
