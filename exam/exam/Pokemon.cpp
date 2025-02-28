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

Pokemon::Pokemon(int _id, std::string _path, std::string _name, int _type1, int _type2, int _evoState, std::map<STAT, int> _stats, std::vector<int> _movePool)
{
	isAlive = true;

	moves.push_back(Move());
	moves.push_back(Move());
	moves.push_back(Move());
	moves.push_back(Move());

	id = _id;
	path = _path;
	name = _name;
	type1 = _type1;
	type2 = _type2;
	evolution_state = _evoState;
	stats = _stats;
	stats[CURRENTHP] = stats[HP];
	movePool = _movePool;
	int tmp = iRand(1, 4096);
	if (tmp == 1)
		shiny = true;
	else
		shiny = false;
}

Pokemon::~Pokemon()
{
	//delete m_texture;
}

void Pokemon::Update()
{
	//Pour les combats seulement ?
}

void Pokemon::Draw(sf::RenderWindow& _window, int _DrawType)
{
}