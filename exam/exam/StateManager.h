#pragma once
#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "GameState.h"
#include "WildPokemonState.h"

#include "tools.h"


enum STATE { MENU, GAME, WILD_POKEMON };

class StateManager
{
	static State* m_currentState;
	static GameState* gameState;
	static MenuState* menuState;
	static WildPokemonState* wildPkmState;

	static Player m_player;

	sf::RenderWindow* m_window;
	sf::Event event;
	sf::Vector2f mousePos;

	bool isRunning;
public:
	StateManager();
	~StateManager();

	static void ChangeState(int _id);

	void Loop();
};