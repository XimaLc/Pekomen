#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/graphics.hpp>

#include "Team.h"
#include "Ball.h"

enum Types { Steel = 1, Fighting, Dragon, Water, Electric, Fairy, Fire, Ice, Bug, Normal, Grass, Poison, Psychic, Rock, Ground, Ghost, Dark, Flying };
enum TEXTURE_TYPE {BALL, ACTION_BAR};

class DB
{
private:
	static sf::Texture ballsTexture;
	static sf::Texture dialogueBarreTexture;
	static std::map<std::string, sf::Texture> pokemonTextures;
public:
	static std::string removeUnderscore(std::string _str);
	static std::vector<int> stringToVectorInt(std::string str);

	static Pokemon getPokemonById(int _id);

	static std::vector<Pokemon> getPokemons(int _startId, int _amount);

	static std::vector<Pokemon> getSelectablePokemons(int _startId, int _amount);
	
	static Ball getBallByID(int _id);

	static Move getMoveById(int _id);
	static std::vector<Move> getMoves(std::vector<int> _movePool, int _startId, int _amount);
	static void saveTeam(Team team);
	static void loadTeam(int playerId);
	static std::vector<Move> getMovePool(std::vector<int> _movePool);

	static void loadTextures();

	static sf::Texture* getTexture(std::string path);
	static sf::Texture* getTexture(TEXTURE_TYPE _type);
	static sf::Texture* getTextureByID(int ID);
	static std::string getPathByID(int ID);
};