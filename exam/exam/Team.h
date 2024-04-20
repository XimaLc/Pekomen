#pragma once
#include "Pokemon.h"

#include <iostream>

class Team
{
private:
	std::string name;
	std::vector<Pokemon> m_team;

public:
	Team();

	void addMove(Move _move, int moveIndex, int teamIndex);
	
	void save();
	
	void load();
	
	inline void addPokemon(Pokemon _p, int i) { m_team[i] = _p; }
	inline std::vector<Pokemon> getPokemons() { return m_team; }
};