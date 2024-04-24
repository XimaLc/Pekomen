#include "Pokemon.h"
#include "tools.h"
#include "DB.h"

void Pokemon::setTypes(int _type1, int _type2)
{
	type1 = _type1;
	type2 = _type2;
}

void Pokemon::setMoveId(int index, int id)
{
	moves[index].setId(id);
}

Pokemon::Pokemon()
{
	isAlive = true;

	moves.push_back(Move());
	moves.push_back(Move());
	moves.push_back(Move());
	moves.push_back(Move());
}

Pokemon::Pokemon(int _id, std::string _path, std::string _name, int _type1, int _type2, int _evoLevel, int _evoTarget, int _evoState, std::map<STAT, int> _stats, std::vector<int> _movePool)
{
	isAlive = true;

	id = _id;
	path = _path;
	name = _name;
	type1 = _type1;
	type2 = _type2;
	evolution_level = _evoLevel;
	evolution_target = _evoTarget;
	evolution_state = _evoState;
	stats = _stats;
	stats[CURRENTHP] = stats[HP];
	stats[XP] = 0;
	stats[LVL] = 0;
	movePool = _movePool;
	int tmp = iRand(1, 4096);
	if (tmp == 1)
		shiny = true;
	else
		shiny = false;


	moves.push_back(DB::getMoveById(_movePool[0]));
	moves.push_back(Move());
	moves.push_back(Move());
	moves.push_back(Move());
}

void Pokemon::setRandomMoves()
{
	moves[0] = DB::getMoveById(movePool[iRand(1, 30)]);
	moves[1] = DB::getMoveById(movePool[iRand(1, 30)]);
	moves[2] = DB::getMoveById(movePool[iRand(1, 30)]);
	moves[3] = DB::getMoveById(movePool[iRand(1, 30)]);
}

Pokemon::~Pokemon()
{
	//delete m_texture;
}

void Pokemon::takeDamages(int _damages)
{
	stats[CURRENTHP] -= _damages;

	if (stats[CURRENTHP] <= 0)
	{
		stats[CURRENTHP] = 0;
		isAlive = false;
	}
}

void Pokemon::levelUp()
{
	if (stats[XP] >= 100)
	{
		stats[LVL] += 1;
		evolve();
	} 
}