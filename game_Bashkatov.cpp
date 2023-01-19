#include "game_Bashkatov.h"
#include <iostream>
using std::cin; using std::cout; using std::vector;
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
		cin >> pl.name;
		pl.cube1 = pl.cube2 = pl.cube3 = pl.cubew = 0;
		pl.token_cube = pl.token_structures = pl.win_points = 0;
		pl.gold = pl.wood = pl.stone = 0;
		pl.military_register = 0;
		this->Pl.push_back(pl);
	}
	this->phase++;
}
Game_Bashkatov::Game_Bashkatov(const Game_Bashkatov& Game)
{
	player pl;
	this->year = Game.year;
	this->phase = Game.phase;
	this->kolvoigr = Game.kolvoigr;
	for (int i = 0; i < kolvoigr; i++)
	{
		this->Pl.at(i) = Game.Pl.at(i);
	}
}
Game_Bashkatov::~Game_Bashkatov() {
	//it's just static lol
}
bool Game_Bashkatov::comp(player const& lhs, player const& rhs)
{
	return lhs.win_points < rhs.win_points;
}
void Game_Bashkatov::phase1()
{
	if (this->year == 1 && this->phase==1) {
		int choose = 0;
		for (int i = 0;i < kolvoigr;i++) {
			for (int j = 0; j < 2; j++) {
				cin >> choose;
				if (choose == 1) {
					Pl.at(i).gold++;
				}
				else if (choose == 2) {
					Pl.at(i).wood++;
				}
				else if (choose == 3) {
					Pl.at(i).stone++;
				}
			}
		}
	}
	else
	{
		std::vector<player*> chosen;
		int max_structure = 0;
		int max_resource = 0;

		for (player Plr : this->Pl)
		{
			if (Plr.str.size() == max_structure)
			{
				if (Plr.wood + Plr.gold + Plr.stone == max_resource)
				{
					chosen.push_back(&Plr);
				}
				else if (Plr.wood + Plr.gold + Plr.stone > max_resource)
				{
					max_resource = Plr.wood + Plr.gold + Plr.stone;

					chosen.empty();
					chosen.push_back(&Plr);
				}
			}
			else if (Plr.str.size() > max_structure)
			{
				chosen.empty();
				chosen.push_back(&Plr);
				max_structure = Plr.str.size();
				max_resource = Plr.wood + Plr.gold + Plr.stone;
			}
		}
		if (chosen.size() == 1)
		{
			chosen.front()->cube1 = cube();
			chosen.front()->cube2 = cube();
			chosen.front()->cube3 = cube();
		}
		else if (chosen.size() > 1)
		{
			int choose = 0;
			for (int i = 0; i < kolvoigr; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cin >> choose;
					if (choose == 1)
					{
						Pl.at(i).gold++;
					}
					else if (choose == 2)
					{
						Pl.at(i).wood++;
					}
					else if (choose == 3)
					{
						Pl.at(i).stone++;
					}
				}
			}
		}
	}
	this->phase++;
}
void Game_Bashkatov::phase2()
{
	this->phase++;
}
void Game_Bashkatov::phase3()
{
	vector<player> candidates;
	int max_structures = this->Pl.at(0).str.size();

	for (auto g : this->Pl)
	{
		if (g.str.size() > max_structures)
		{
			max_structures = g.str.size();
			candidates.clear();
			candidates.push_back(g);
		}
		else if (g.str.size() == max_structures) candidates.push_back(g);
	}
	for (int i = 0; i < this->Pl.size(); i++)
	{
		for (auto c : candidates)
		{
			if (this->Pl.at(i).name == c.name)
			{
				this->Pl.at(i).win_points++;
			}
		}
	}
	this->phase++;
}
void Game_Bashkatov::phase4()
{
	this->phase++;
}
void Game_Bashkatov::phase5()
{
	vector<player> candidates;
	int min_structures = this->Pl.at(0).str.size();
	for (auto g : this->Pl)
	{
		if (g.str.size() < min_structures)
		{
			min_structures = g.str.size();
			candidates.clear();
			candidates.push_back(g);
		}
		else if (g.str.size() == min_structures)
		{
			candidates.push_back(g);
		}
	}
	if (candidates.size() == 1)
	{

	}
	else
	{
		std::vector<player> new_candidates;
		int cnt = 0;
		int sum_min = candidates[0].gold + candidates[0].wood + candidates[0].stone;
		for (auto c : candidates)
		{
			int sum_p = c.gold + c.wood + c.stone;
			if (sum_p < sum_min)
			{
				sum_min = c.gold + c.wood + c.stone;
				new_candidates.clear();
				new_candidates.push_back(c);
			}
			else if (sum_min == sum_p) new_candidates.push_back(c);
		}
		if (cnt == 1)
		{

		}
	}
}
void Game_Bashkatov::phase6()
{
	this->phase++;
}
void Game_Bashkatov::phase7()
{
	int* Max_First;
	int* Max_Second;
	for (auto play : this->Pl)
	{
		while (play.gold + play.wood + play.stone > 2)
		{
			if (play.military_register == 9)
			{
				break;
			}

			play.military_register++;

			if (play.gold > play.wood)
			{
				play.gold--;
				if (play.wood > play.stone)
				{
					play.wood--;
				}
				else
				{
					play.stone--;
				}
			}
			else
			{
				play.wood--;

				if (play.gold > play.stone)
				{
					play.gold;
				}
				else
				{
					play.stone--;
				}
			}
		}
	}
	this->phase++;
}

void Game_Bashkatov::phase8()
{
	this->phase++;
}

void Game_Bashkatov::defense_level(const char* Ename, int Khelp, player& player)
{

}
bool Game_Bashkatov::load(const char* filename)
{
	int k = 0;
	std::ifstream file;
	std::string line;
	std::string buf = "";
	file.open(filename);
	while (std::getline(file, line))
	{
		k++;
	}
	file.close();

	file.open(filename);
	int b = 0;
	for (int i = 0; i < k; i++)
	{
		while (std::getline(file, line))
		{

			for (int i = 0; i < line.size(); i++)
			{

			}
		}
		for (auto i : Pl)
		{
			std::cout << i.name;
		}
		file.close();
		return 1;
	}
}
bool Game_Bashkatov::save_game(const char* filename)
{
	std::ofstream f;
	int k = 0;
	int* info = new int(kolvoigr);
	f.open(filename);
	for (int i = 0; i < kolvoigr; i++)
	{
		k = 0;
		f << i << "["
			<< Pl.at(i).name << "]["
			<< Pl.at(i).cube1 << "][" << Pl.at(i).cube2 << "][" << Pl.at(i).cube3 << "]["
			<< Pl.at(i).cubew << "][" << Pl.at(i).gold << "][" << Pl.at(i).wood << "]["
			<< Pl.at(i).stone << "][" << Pl.at(i).win_points << "][" << Pl.at(i).token_cube << "]["
			<< Pl.at(i).token_structures << "][" << Pl.at(i).military_register << "]";
		for (int j = 0; j < Pl.at(i).str.size(); j++)
		{
			f << "[" << Pl.at(i).str[j] << "]";
			k++;

		}
		f << "{" << k << "}";
		f << '\n';
	}
	f.close();
	return 1;

}
void Game_Bashkatov::phase246()
{

}
void Game_Bashkatov::phase246_bones()
{

	for (int i = 0; i < kolvoigr; i++)
	{

	}
}