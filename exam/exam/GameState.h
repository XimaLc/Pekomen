#pragma once
#include "InGameMenu.h"
#include "State.h"
#include "Bouton.h"
#include "Map.h"
#include "Player.h"
#include "Pnj.h"
#include "DialogueBarre.h"

#include <SFML/Graphics.hpp>

class GameState : public State
{
	bool gameHasFocus;
	bool hasMove;

	InGameMenu m_inGameMenu;
	
	Map map;

	float timer;

	Pnj m_healer;
	Player* m_player;

	sf::Vector2i lookingAt;

	static DialogueBarre m_dialoguesBox;

	sf::View mapView;
public:
	~GameState();
	GameState();
	GameState(Player& _player);

	static void setDialogue(std::string _str);

	virtual void Update(sf::Vector2f _mousePos);
	virtual void Draw(sf::RenderWindow& _window);
	virtual void HandleKeyboard(sf::Event _event);
};