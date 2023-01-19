#include "game_Bashkatov.h"
using std::cin; using std::cout;
unsigned int cube() {
	return 1 + rand() % 6;
}
Game_Bashkatov::Game_Bashkatov() {
	player pl;
	this->year = 1;
	this->phase = 0;
	for (int i = 0; i < 2;i++) {
		pl.name = i;
		pl.cube1 = pl.cube2 = pl.cube3 = pl.cubew = 0;
		pl.token_cube = pl.token_structures = pl.win_points = 0;
		pl.gold = pl.wood = pl.stone = 0;
		pl.military_register = 0;
		this->Pl.push_back(pl);
	}
}
Game_Bashkatov::Game_Bashkatov(const int num) {
	player pl;
	this->year = 1;
	this->phase = 0;
	this->kolvoigr = num;
	for (int i = 0; i < kolvoigr;i++) {
		pl.name = i;
		pl.cube1 = pl.cube2 = pl.cube3 = pl.cubew = 0;
		pl.token_cube = pl.token_structures = pl.win_points = 0;
		pl.gold = pl.wood = pl.stone = 0;
		pl.military_register = 0;
		this->Pl.push_back(pl);
	}
}void Game_Bashkatov::phase1()
{
	if (year == 1)
	{
		int chose;
		for (int i = 0; i < kolvoigr; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (chose == 1)
				{
					Pl.at(i).gold++;
				}
				else if (chose == 2)
				{
					Pl.at(i).wood++;
				}
				else if (chose == 3)
				{
					Pl.at(i).stone++;
				}
			}
		}
	}
	else
	{

	}
}
void Game_Bashkatov::phase3()
{
	std::cout << "##### Year " << this->year << " Phase 3. Royal award ######" << std::endl;
	std::vector<player> Pl;
	int max_buildings = this->Pl[0].Structure.size();
	
	for (auto g : this->Pl)
	{
		if (g.Structure.size() > max_Structure)
		{
			max_buildings = g.Structure.size();
			kolvoigr.clear();
			kolvoigr.push_back(g);
		}
		else if (g.Structure.size() == max_buildings) kolvoigr.push_back(g);
	}
	
	for (int i = 0; i < this->Pl.size(); i++)
	{
		for (auto c : kolvoigr)
		{
			if (this->Pl[i].name == c.name)
			{
				std::cout << "Player " << c.name << " receives win point" << std::endl;
				this->Pl[i].win_points++;
			}
		}
	}
}

void Game_Bashkatov::phase5()
{

}

void Game_Bashkatov::phase7()
{

}

void Game_Bashkatov::phase8()
{

}

void Game_Bashkatov::defense_level(const char* Ename, int Khelp, player& player)
{

}