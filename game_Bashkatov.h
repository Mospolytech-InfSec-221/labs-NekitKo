#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using std::string; using std::cin; using std::cout; using std::vector;
class Game_Bashkatov {
private:
	enum Structure {
		statue,church,cathedral,inn,market,farm,tradeguild,
		barrack,palisade,stable,stoneWall,fortress,stockade,townhall,embassy
	};
	struct player {
		string name;
		unsigned int cube1, cube2, cube3, cubew,gold, wood, stone, token_cube, 
			token_structures, military_register, win_points;
		bool advisorTrF;
		vector<Structure> str;
	};
	struct Advisor {
		string nameAD;
		string namePL;
	};
	vector<Advisor>Advisor;
	unsigned int phase, year;
	int enemy[5] = { 1,2,3,4,5 };
	int kolvoigr;
	vector <player> Pl;

public:
	Game_Bashkatov();
	Game_Bashkatov(const int);
	Game_Bashkatov(const Game_Bashkatov&);
	~Game_Bashkatov();
	bool comp(player const& lhs, player const& rhs);
	void phase1();
	void phase2();
	void phase3();
	void phase4();
	void phase5();
	void phase6();
	void phase7();
	void phase8();
	bool load(const char*);
	bool save_game(const char*);
	void phase246();
	void phase246_bones();
	void defense_level(const char* Ename, int Khelp, player& player);
};