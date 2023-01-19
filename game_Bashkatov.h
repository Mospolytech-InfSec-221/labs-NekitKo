#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::string; using std::cin; using std::cout; using std::vector;
class Game_Bashkatov {
private:
	struct player {
		string name;
		unsigned int cube1, cube2, cube3, gold, wood, stone, token_cube, 
			token_structures, military_register, risk_cards, win_points;
		bool advisorTrF;
	};
	unsigned int phase, year;
	vector <unsigned int> advisor;
	vector <unsigned int> player;


};