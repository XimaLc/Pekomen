#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Move.h"
#include <map>

#include <iostream>
enum STAT {HP, CURRENTHP, ATK, DEF, SPEA, SPED, SPD, BST, XP};

class Pokemon
{
	int id;
	std::string path;
	std::string name;
	int type1;
	int type2;
	int evolution_state;
	std::map<STAT, int> stats;
	std::vector<int> movePool;
	bool shiny;
	std::vector<Move> moves;

	sf::Texture* m_texture;
	sf::Sprite m_sprite;

	bool isAlive;
public:
	inline void setId(int _id) { id = _id; }
	inline void setPath(std::string _path) { path = _path; }
	inline void setName(std::string _name) { name = _name; }
	inline void setEvolutionState(int _evoState) { evolution_state = _evoState; }
	inline void setStats(std::map<STAT, int> _stats) { stats = _stats; }
	inline void setMovePool(std::vector<int> _movePool) { movePool = _movePool; }
	inline void setMove(Move move, int i) { moves[i] = move; }
	inline void getTexture() { return; }
	void setTypes(int _type1, int _type2);

	void setMoveId(int index, int id);

	inline int getId() { return id; }
	inline std::string getPath() { return path; }
	inline std::string getName() { return name; }
	inline std::map<STAT, int> getStats() { return stats; }
	inline int getStat(STAT _stat) {  return stats[_stat]; }
	inline std::vector<int> getMovePool() { return movePool; }
	inline int getType1() { return type1; }
	inline int getType2() { return type2; }
	inline int getEvolutionState() { return evolution_state; }
	inline bool getSiny() { return shiny; }
	inline std::vector<Move> getMoves() { return moves; }

	Pokemon();
	Pokemon(int _id, std::string _path, std::string _name, int _type1, int _type2, int _evoState, std::map<STAT, int> _stats, std::vector<int> _movePool);
	void setRandomMoves();
	~Pokemon();

	void takeDamages(int _damages);

	inline bool getIsAlive() { return isAlive; }
	inline void switchAlive() { isAlive = !isAlive; }
};