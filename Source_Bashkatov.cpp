#include "game_Bashkatov.h"

#include <iostream>
using std::sin;
int main()
{
	int kolvo, k = 0;
	cin >> kolvo;
	Game_Bashkatov Game(kolvo);
	Game.save_game("save_game.txt");
}