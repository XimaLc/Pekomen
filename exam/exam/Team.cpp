#include "Team.h"
#include "DB.h"
#include "GameState.h"

Team::Team()
{
	//m_team.push_back(DB::getPokemonById(1));
	//m_team.push_back(DB::getPokemonById(2));
	//m_team.push_back(DB::getPokemonById(3));
	//m_team.push_back(DB::getPokemonById(4));
	//m_team.push_back(DB::getPokemonById(5));
	//m_team.push_back(DB::getPokemonById(6));

	m_team.push_back(Pokemon());
	m_team.push_back(Pokemon());
	m_team.push_back(Pokemon());
	m_team.push_back(Pokemon());
 	m_team.push_back(Pokemon());
	m_team.push_back(Pokemon());
}

void Team::addMove(Move _move, int moveIndex, int teamIndex)
{
	m_team[teamIndex].setMove(_move, moveIndex);
}

void Team::save()
{
	DB::saveTeam(*this);
}

void Team::load()
{
	int pId1, pId2, pId3, pId4, pId5, pId6, plvl1, plvl2, plvl3, plvl4, plvl5, plvl6, mId1, mId2, mId3, mId4, mId5, mId6, mId7, mId8, mId9, mId10, mId11, mId12, mId13, mId14, mId15, mId16, mId17, mId18, mId19, mId20, mId21, mId22, mId23, mId24;
	pId1 = pId2 = pId3 = pId4 = pId5 = pId6 = plvl1 = plvl2 = plvl3 = plvl4 = plvl5 = plvl6 = mId1 = mId2 = mId3 = mId4 = mId5 = mId6 = mId7 = mId8 = mId9 = mId10 = mId11 = mId12 = mId13 = mId14 = mId15 = mId16 = mId17 = mId18 = mId19 = mId20 = mId21 = mId22 = mId23 = mId24 = -1;
	std::ifstream file("../Files/team.dat");
	if (file.is_open())
	{
		file >> pId1 >> plvl1 >> mId1 >> mId2 >> mId3 >> mId4 >> pId2 >> plvl2 >> mId5 >> mId6 >> mId7 >> mId8 >> pId3 >> plvl3 >> mId9 >> mId10 >> mId11 >> mId12 >> pId4 >> plvl4 >> mId13 >> mId14 >> mId15 >> mId16 >> pId5 >> plvl5 >> mId17 >> mId18 >> mId19 >> mId20 >> pId6 >> plvl6 >> mId21 >> mId22 >> mId23 >> mId24;
		file.close();
	}

	if (pId1 != -1)
	{
		m_team[0] = DB::getPokemonById(pId1);
		m_team[0].setStat(LVL, plvl1);
		if (mId1 != -1)
			m_team[0].setMove(DB::getMoveById(mId1), 0);
		if (mId2 != -1)
			m_team[0].setMove(DB::getMoveById(mId2), 1);
		if (mId3 != -1)
			m_team[0].setMove(DB::getMoveById(mId3), 2);
		if (mId4 != -1)
			m_team[0].setMove(DB::getMoveById(mId4), 3);
	}

	if (pId2 != -1)
	{
		m_team[1] = DB::getPokemonById(pId2);
		m_team[1].setStat(LVL, plvl2);
		if (mId5 != -1)
			m_team[1].setMove(DB::getMoveById(mId5), 0);
		if (mId6 != -1)
			m_team[1].setMove(DB::getMoveById(mId6), 1);
		if (mId7 != -1)
			m_team[1].setMove(DB::getMoveById(mId7), 2);
		if (mId8 != -1)
			m_team[1].setMove(DB::getMoveById(mId8), 3);
	}
	if (pId3 != -1)
	{
		m_team[2] = DB::getPokemonById(pId3);
		m_team[2].setStat(LVL, plvl3);
		if (mId9 != -1)
			m_team[2].setMove(DB::getMoveById(mId9), 0);
		if (mId10 != -1)
			m_team[2].setMove(DB::getMoveById(mId10), 1);
		if (mId11 != -1)
			m_team[2].setMove(DB::getMoveById(mId11), 2);
		if (mId12 != -1)
			m_team[2].setMove(DB::getMoveById(mId12), 3);
	}

	if (pId4 != -1)
	{
		m_team[3] = DB::getPokemonById(pId4);
		m_team[3].setStat(LVL, plvl4);
		if (mId13 != -1)
			m_team[3].setMove(DB::getMoveById(mId13), 0);
		if (mId14 != -1)
			m_team[3].setMove(DB::getMoveById(mId14), 1);
		if (mId15 != -1)
			m_team[3].setMove(DB::getMoveById(mId15), 2);
		if (mId16 != -1)
			m_team[3].setMove(DB::getMoveById(mId16), 3);
	}

	if (pId5 != -1)
	{
		m_team[4] = DB::getPokemonById(pId5);
		m_team[4].setStat(LVL, plvl5);
		if (mId17 != -1)
			m_team[4].setMove(DB::getMoveById(mId17), 0);
		if (mId18 != -1)
			m_team[4].setMove(DB::getMoveById(mId18), 1);
		if (mId19 != -1)
			m_team[4].setMove(DB::getMoveById(mId19), 2);
		if (mId20 != -1)
			m_team[4].setMove(DB::getMoveById(mId20), 3);
	}

	if (pId6 != -1)
	{
		m_team[5] = DB::getPokemonById(pId6);
		m_team[5].setStat(LVL, plvl6);
		if (mId21 != -1)
			m_team[5].setMove(DB::getMoveById(mId21), 0);
		if (mId22 != -1)
			m_team[5].setMove(DB::getMoveById(mId22), 1);
		if (mId23 != -1)
			m_team[5].setMove(DB::getMoveById(mId23), 2);
		if (mId24 != -1)
			m_team[5].setMove(DB::getMoveById(mId24), 3);
	}
}

void Team::addStarter(int _type)
{
	m_team[0] = DB::getPokemonById(_type);
	m_team[1] = Pokemon();
	m_team[2] = Pokemon();
	m_team[3] = Pokemon();
	m_team[4] = Pokemon();
	m_team[5] = Pokemon();
}

void Team::evolvePokemons()
{
	for(int i = 0; i < m_team.size(); i++)
	{
		if (m_team[i].canEvolve())
		{
			int x = m_team[i].getStat(LVL);
			std::string tmp = m_team[i].getName();
			m_team[i] = DB::getPokemonById(m_team[i].getEvolutionTarget());
			m_team[i].setStat(LVL, x);
			GameState::setDialogue("Votre " + tmp + " evolue en " + m_team[i].getName());
		}
	}
}

bool Team::isAllDead()
{
	for (auto& pkm : m_team)
	{
		if (pkm.getIsAlive())
			return false;
	}
	return true;
}

void Team::healAll()
{
	for (auto& pkm : m_team)
	{
		pkm.heal();
		pkm.setIsAlive(true);
	}
}
	