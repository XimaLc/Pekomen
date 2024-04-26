#pragma once
#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "GameState.h"
#include "WildPokemonState.h"
#include "NewGameState.h"

#include "tools.h"


enum STATE { MENU_STATE, GAME_STATE, WILD_POKEMON_STATE, NEW_GAME_STATE};

class StateManager
{
	static State* m_currentState;
	static GameState* gameState;

	sf::RenderWindow* m_window;
	sf::Event event;
	sf::Vector2f mousePos;

	static Player m_player;
	sf::Texture playerTexture;
public:
	static bool isRunning;
	
	StateManager();
	~StateManager();

	static inline Player getPlayer() { return m_player; }
	static inline Player* getPlayer2() { return &m_player; }
	static void ChangeState(int _id);

	void Loop();
};